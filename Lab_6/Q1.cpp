#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Message
{
private:
    string msg;

public:
    Message(string m) : msg(m) {}
    string toString() const
    {
        return msg;
    }
    void setString(string m)
    {
        msg = m;
    }
};

class SMS : public Message
{
private:
    string recipientContactNo;

public:
    SMS(string n, string m) : Message(m), recipientContactNo(n) {}
    string getNum() const
    {
        return recipientContactNo;
    }
    void setNum(string n)
    {
        recipientContactNo = n;
    }
    string toString() const
    {
        return ("To: " + getNum() + "\nMessage: " + Message::toString());
    }
};

class Email : public Message
{
private:
    string sender;
    string receiver;
    string subject;

public:
    Email(string s, string r, string sub, string m) : Message(m), sender(s), receiver(r), subject(sub) {}
    string getSender() const
    {
        return sender;
    }
    string getReceiver() const
    {
        return receiver;
    }
    string getSubject() const
    {
        return subject;
    }
    void setSender(string s)
    {
        sender = s;
    }
    void setReceiver(string r)
    {
        receiver = r;
    }
    void setSubject(string s)
    {
        subject = s;
    }
    string toString() const
    {
        return ("Sender: " + getSender() + "\nReceiver: " + getReceiver() + "\nSubject: " + getSubject() + "\nMessage: " + Message::toString());
    }
};

bool ContainsKeyword(const Message &messageObject, const string &keyword)
{
    return messageObject.toString().find(keyword) != string::npos;
}

string Encode(const string &msg)
{
    string encoded = msg;
    for (char &c : encoded)
    {
        if (isalpha(c))
        {
            if (c == 'A')
                c = 'Z';
            else if (c == 'a')
                c = 'z';
            else
                c++;
        }
    }
    return encoded;
}

int main()
{
    Message msg("Hey! How's it going?");
    SMS sms("03191442389", msg.toString());
    Email email("Laiba Khan", "Yumna Salem", "Class Schedule", "Hey! Can you send the class Schedule for this month?");
    cout << "Sms and Email Created!" << endl;
    string keyword;
    cout << "Enter the word to search in emails: ";
    getline(cin, keyword);

    if (ContainsKeyword(email, keyword))
    {
        cout << "Found it!" << endl;
    }
    else
        cout << "Not Found!" << endl;

    cout << endl;
    cout << "Original SMS:" << endl;
    cout << sms.toString();
    string encoded = Encode(msg.toString());
    sms.setString(encoded);

    cout << "\nEncoded SMS:" << endl;
    cout << sms.toString();
    return 0;
}
