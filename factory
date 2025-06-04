#include <iostream>
#include <string>
#include <memory>

using namespace std;

// INotifier
class INotifier {
public:
    virtual string notify(const string& message) const = 0;
    virtual ~INotifier() = default;
};

class SMSNotifier : public INotifier {
public:
    string notify(const string& message) const override {
        return " Se Envia SMS : '" + message + "'";
    }
};

class EmailNotifier : public INotifier {
public:
    string notify(const string& message) const override {
        return " Se Envia correo electrónico: '" + message + "'";
    }
};

class PushNotifier : public INotifier {
public:
    string notify(const string& message) const override {
        return " Se Envia notificación Push : '" + message + "'";
    }
};

//  Factory  
class NotifierCreator {
public:
    virtual INotifier* FactoryMethod() const = 0;

    string SomeOperation(const string& message) const {
        INotifier* notifier = this->FactoryMethod();
        string result = "Resultado: " + notifier->notify(message);
        delete notifier;
        return result;
    }

    virtual ~NotifierCreator() = default;
};

class SMSNotifierCreator : public NotifierCreator {
public:
    INotifier* FactoryMethod() const override {
        return new SMSNotifier();
    }
};

class EmailNotifierCreator : public NotifierCreator {
public:
    INotifier* FactoryMethod() const override {
        return new EmailNotifier();
    }
};

class PushNotifierCreator : public NotifierCreator {
public:
    INotifier* FactoryMethod() const override {
        return new PushNotifier();
    }
};

void ClientCode(const NotifierCreator& creator, const string& message) {
    cout << creator.SomeOperation(message) << endl;
}

// Main 
int main() {
    string mensaje = "Hola.";

    cout << "App: Usando SMSNotifierCreator:\n";
    NotifierCreator* smsCreator = new SMSNotifierCreator();
    ClientCode(*smsCreator, mensaje);
    delete smsCreator;

    cout << "\nApp: Usando EmailNotifierCreator:\n";
    NotifierCreator* emailCreator = new EmailNotifierCreator();
    ClientCode(*emailCreator, mensaje);
    delete emailCreator;

    cout << "\nApp: Usando PushNotifierCreator:\n";
    NotifierCreator* pushCreator = new PushNotifierCreator();
    ClientCode(*pushCreator, mensaje);
    delete pushCreator;

    return 0;
}
