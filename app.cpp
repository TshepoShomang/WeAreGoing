#include <iostream> 
using namespace std;


bool running = true;

class SignIn{
private:
    string name, surname;
    int cardNumber = 0;
    bool signedIn;

public:
    void setName(){
        cout << "What is your first name? ";
        cin >> name;
    }
    string getName(){
        return name;
    }
    
    void setSurname(){
        cout << "What is your last name? ";
        cin >> surname;
    }
    string getSurname(){
        return surname;
    }

    void setCardNumber(){
        cout << "Please enter card number";
        cin >> cardNumber;
    }
    int getCardNumber(){
        return cardNumber;
    }

    void setSigned(char signOut){
        if (name == "" & surname == "" & cardNumber == 0){
            signedIn = false;
        }
        else if (signOut == 'y'){
            signedIn = false;
        }
        else{
            signedIn = true;
        }
    }
    void setSignOut(){

    }
    bool signedin(){
        return signedIn;
    }

   

};

class Money{
private:
    float balance = 0;
    float reload;
public:  
    void setLoader(){
        cout << "How much do you want to load?";
        cin >> reload;
    }
    float getLoaded(){
        return reload;
    }
    void setBalance(){
        balance = balance + reload;
    }
    void getCurrentBalance(){
        cout << "Your current balance is R" << balance << endl;
    }
    double getBalance(){
        return balance;
    }
};

class Tapping{
private:
    bool tapIn = true;
    bool tapOut = false;
    bool currentState = false;
    bool previousState;
    bool balanceCheck;
    string amount;
    char tap;
    string outcome;

public:
    void setCurrentState(){
        cout << "Do you want to tap in or out(i/o)";
        cin >> tap; cout << endl;


        if (tap == 'i' || tap == 'I'){
            if (balanceCheck == true){
                cout << "You have tapped in, please proceed ->" << endl;
                currentState = true;
            }else{
                cout << "You have no funds, Please reload" << endl;
                currentState = false;
            }
            
            cout << "You have tapped in, please proceed ->" << endl;
            currentState = true;
        }
        else if (tap == 'o' || tap == 'O'){
            cout << "You have tapped out, good bye" << endl;
            currentState = false;
        }
        else {
            cout << "You have entered an invalid option" << endl;
            cout << "Do you want to tap in or out(i/o)";
            cin >> tap; cout << endl;
        }
    }
    void setPreviousState(){
        previousState = currentState;
    }   
    bool getPreviousState(){
        return previousState;
    }

    void setTap(){
        if (tap == 'I' || tap == 'i' & previousState == false){
            outcome = "pay";
        }
        else if (tap == 'I' || tap == 'i' & previousState == true){
            outcome = "penalty";
        }

        if (tap == 'O' || tap == 'o' & previousState == true){
            outcome = "pay";
        }
        else if (tap == 'O' || tap == 'o' & previousState == false){
            outcome = "penalty";
        }
    }

    string getTap(){
        return outcome;
    }
//I am here
    void setEnoughFunds(double balance){
        if (balance > 20){
            amount = "Enough";
        }
        else if (balance < 20){
            amount = "LowBalance";
        }
        else if (balance < 10){
            amount = "NoFunds";
        }
    }
    void setBalanceCheck(){
        if (amount == "Enough"){
            cout << "Enough Funds" << endl;
            balanceCheck = true;
        }
        else if (amount == "LowBalance"){
            cout << "Low Balance" << endl;
            balanceCheck = true;
        }
        else if (amount == "NoFunds") {
            cout << "No Funds X" << endl;
            balanceCheck = false;
        }
    }

};


class Options{
    private:
        char currentOption, back;
    
    public:
        void setCurrentOption(){
            cout << "What would you like to do" << endl;
            cout << "Please press (t) to tap..." << endl;
            cout << "a) Veiw Profile" << endl;
            cout << "b) Reload" << endl;
            cout << "c) Check Balance" << endl;
            cout << "d) Status" << endl;
            cout << "e) Sign Out" << endl;
            cin >> currentOption;
        }
        char getCurrentOption(){
            return currentOption;
        }

        void setBack(){
            cout << "Press any button to go back" << endl;
            cin >> back;
        }
        char getBack(){
            return back;
        }
        
};


int main(){
    SignIn sign;
    Money money;
    Tapping tap;
    Options options;


    while (running){
        sign.setSigned('y');
        while (sign.signedin() == false){
            sign.setName();
            sign.setSurname();
            sign.setCardNumber();
            sign.setSigned('n');
        }

        options.setCurrentOption();

        

        if (options.getCurrentOption() == 't' || options.getCurrentOption() == 't'){
            tap.setEnoughFunds(money.getBalance());
            tap.setBalanceCheck();
            tap.setPreviousState();
            cout << tap.getPreviousState() << endl;
            tap.setCurrentState();
            tap.setTap();
            cout << tap.getTap() << endl;
            cout << tap.getPreviousState() << endl;
            options.setBack();
        }    
        else if (options.getCurrentOption() == 'a' || options.getCurrentOption() == 'A'){
            cout << "Name: " << sign.getName() << " " << sign.getSurname() << endl;
            cout << "Card Number: " << sign.getCardNumber() << endl;
            options.setBack();
        }
        else if (options.getCurrentOption() == 'b' || options.getCurrentOption() == 'B'){
            money.setLoader();
            money.setBalance();
            money.getCurrentBalance();
            options.setBack();
        }
        else if (options.getCurrentOption() == 'c' || options.getCurrentOption() == 'C'){
            money.getCurrentBalance();
            options.setBack();
        }
        else if (options.getCurrentOption() == 'd' || options.getCurrentOption() == 'D'){
            
        }
        else if (options.getCurrentOption() == 'e' || options.getCurrentOption() == 'E'){
           sign.setSigned('n');
        }else{
            cout << "The option you chose is invalid please re-enter" << endl;
            options.setBack();
        }
    }    
}


