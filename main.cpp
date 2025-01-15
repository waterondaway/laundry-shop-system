#include <iostream>
#include <iomanip>

using namespace std;

FILE *file_receipt = fopen("transaction.txt","w");

int using_account_no;

void status(string status_method){
    if(status_method == "active"){
        cout << "☑ active";
    }else if(status_method == "busy"){
        cout << " ☒ busy";
    }
}

void println(int fix_length){
    for(int loop_length=0;loop_length<fix_length;loop_length++){
        cout << "|";
    }
    cout << endl;
}

void newspace(){
    cout << endl;
}

void showExit(){
    cout << "  Note : Press (0) to Exit Mode " << endl;
}

struct account_database{
    
    string username;
    string password;
    int userid;
    
}account_folder[100];

class Laundry_Management{
  public:
    float washing_cost;
    float drying_cost;
    string name;
    int laundryID;
  public:
    Laundry_Management(string main_name,int main_laundryID){
      name = main_name;
      laundryID = main_laundryID;
    }
    void setCost(float main_washing_cost,float main_drying_cost){
        this->washing_cost = main_washing_cost;
        this->drying_cost = main_drying_cost;
    }
    
    
};

class Store_Management : public Laundry_Management{
    public:
        float total;
        string A01,A02,B01,B02;
        char approve_status;
        Store_Management(string main_name,int main_laundryID) : Laundry_Management(main_name,main_laundryID){
        }
        string calculate_Price(string machine_select){
            total = 0;
            if(machine_select == "A01" and A01 == "active"){
                total += Laundry_Management::washing_cost;
                approve_status = showReceipt(total,machine_select);
                if(approve_status == 'y' or approve_status == 'Y'){
                    A01 = "busy";
                    fprintf(file_receipt,"UserID : %d  A01 : %.2f  LaundryID : %d\n",account_folder[using_account_no].userid,Laundry_Management::washing_cost,Laundry_Management::laundryID);
                    return "success";
                }else if(approve_status == 'n' or approve_status == 'N'){
                    cout <<"  Note : ☒ Cancel Approving! " << endl;
                }
                else{
                    cout << "  Note : ERROR#!2 | Try Again!  " << endl;
                }
            }else if(machine_select == "A02" and A02 == "active"){
                total += Laundry_Management::washing_cost;
                approve_status = showReceipt(total,machine_select);
                if(approve_status == 'y' or approve_status == 'Y'){
                    A02 = "busy";
                    fprintf(file_receipt,"UserID : %d  A02 : %.2f  LaundryID : %d\n",account_folder[using_account_no].userid,Laundry_Management::washing_cost,Laundry_Management::laundryID);
                    return "success";
                }else if(approve_status == 'n' or approve_status == 'N'){
                    cout <<"  Note : ☒ Cancel Approving! " << endl;
                }else{
                    cout << "  Note : ERROR#!2 | Try Again!  " << endl;
                }
            }else if(machine_select == "B01" and B01 == "active"){
                total += Laundry_Management::drying_cost;
                approve_status = showReceipt(total,machine_select);
                if(approve_status == 'y' or approve_status == 'Y'){
                    B01 = "busy";
                    fprintf(file_receipt,"UserID : %d  B01 : %.2f  LaundryID : %d\n",account_folder[using_account_no].userid,Laundry_Management::washing_cost,Laundry_Management::laundryID);
                    return "success";
                }else if(approve_status == 'n' or approve_status == 'N'){
                    cout <<"  Note : ☒ Cancel Approving! " << endl;
                }else{
                    cout << "  Note : ERROR#!2 | Try Again!  " << endl;
                }
            }else if(machine_select == "B02" and B02 == "active"){
                total += Laundry_Management::drying_cost;
                approve_status = showReceipt(total,machine_select);
                if(approve_status == 'y' or approve_status == 'Y'){
                    B02 = "busy";
                    fprintf(file_receipt,"UserID : %d  B02 : %.2f  LaundryID : %d\n",account_folder[using_account_no].userid,Laundry_Management::washing_cost,Laundry_Management::laundryID);
                    return "success";
                }else if(approve_status == 'n' or approve_status == 'N'){
                    cout <<"  Note : ☒ Cancel Approving! " << endl;
                }else{
                    cout << "  Note : ERROR#!2 | Try Again!  " << endl;
                }
            }else if(machine_select != "A01" and machine_select != "A02" and machine_select != "B01" and machine_select != "B02"){
                cout << "  Not Found | Please Try Again!" << endl;
                return "fail";
            }else{
                cout << "  Washer/Dryer are busy | Please Try Again!" << endl;
                return "fail";
            }
            return "fail";
        }
        char showReceipt(float total,string machine_select){
            newspace();
            println(45);
            cout << "|        " << Laundry_Management::name << " Receipt     |" << endl;
            println(45);
            newspace();
            cout << "UserID : " << account_folder[using_account_no].userid << "  " << machine_select << " : " << total << "฿  " << "LaundryID : " << Laundry_Management::laundryID;
            newspace();
            cout << "(Y) Approve (N) Cancel : "; cin >> approve_status;
            return approve_status;
        }
        void resetStatus(){
            A01 = "active";
            A02 = "active";
            B01 = "active";
            B02 = "active";
        }
        void showWash_Machine();
        void showDry_Machine();
        void showThumbnil(){
            println(37);
            cout << "|      " << Laundry_Management::name << "       |"<< endl;
            println(37);
            newspace();
        }
};

void Store_Management :: showWash_Machine(){
    cout<<"      ";status(A01);
    cout<<"       ";status(A02);
    newspace();
    cout << "    |~~~~~~~~~~~| |~~~~~~~~~~~|" << endl;
    cout << "    |           | |           |" << endl; 
    cout << "    |  Washing  | |  Washing  |" << endl;
    cout << "    |  Machine  | |  Machine  |" << endl;
    cout << "    |    A01    | |    A02    |" << endl;
    cout << "    |___________| |___________|" << endl;
}

void Store_Management :: showDry_Machine(){
    newspace();
    cout<<"      ";status(B01);
    cout<<"       ";status(B02);
    newspace();
    cout << "    |~~~~~~~~~~~| |~~~~~~~~~~~|" << endl;
    cout << "    |           | |           |" << endl;
    cout << "    |    Dry    | |    Dry    |" << endl;
    cout << "    |  Machine  | |  Machine  |" << endl;
    cout << "    |    B01    | |    B02    |" << endl;
    cout << "    |___________| |___________|" << endl;
}

class Entrepreneur_Management : public Laundry_Management{
    public:
        string keys,keyword_input;
        float new_washing_cost,new_drying_cost;
        Entrepreneur_Management(string main_name,int main_laundryID) : Laundry_Management(main_name,main_laundryID){
        }
        void setKeys(string main_keys){
          keys = main_keys;
          }
        string loginSystem(){
            println(45);
            cout << "| Laundry Store |  Entrepreneur Management  |" << endl;
            println(45);
            newspace();
            cout << "  Keys  : "; cin >> keyword_input;
            if(keyword_input == keys){
                cout << "  "; status("active"); newspace();
                newspace();
                return "success";
            }else if(keyword_input == "0"){
                return "exit";
            }else if(keyword_input != keys){
                showExit();
                return "fail";
            }
            return 0;
        }
        float editCost(){
            println(45);
            cout << "| Laundry Store |  Edit Cost Washing/Drying  |" << endl;
            println(45);
            newspace();
            cout << " Washing Cost > "; cin >> new_washing_cost;
            cout << " Drying Cost > "; cin >> new_drying_cost;
            newspace();
            return new_washing_cost,new_drying_cost;
        }
        void showMember(int main_account_no){
            println(40);
            cout << "| Laundry Store |  Account Database    |" << endl;
            println(40);
            newspace();
            for(int account_no=0;account_no<main_account_no;account_no++){
                cout << "  User No." << account_folder[account_no].userid << endl; 
                cout << "  Username : " << account_folder[account_no].username << endl;
                cout << "  Password : " << account_folder[account_no].password << endl;
                newspace();
            }
        }
};

string login_account(){
      string login_username,login_password;
      println(37);
      cout << "| Laundry Store |    Login System   |" << endl;
      println(37);
      newspace();
      cout << "  Username : "; cin >> login_username;
      if(login_username == "0"){
        return "exit";
      }
      cout << "  Password : "; cin >> login_password;
      if(login_password == "0"){
        return "exit";
      }
      for(int account_no = 0;account_no < 100;account_no++){
        if(login_username == account_folder[account_no].username){
          if(login_password == account_folder[account_no].password){
            cout << "  ☑ Login Success | Nice to see you! " << endl;
            newspace();
            using_account_no = account_no;
            return "success";
          }else{
            cout << "  ☒ Password Incorrect | Try Again! " << endl;
            showExit();
            return "fail";
          }
        }else if(account_no == 99){
          cout << "  ☒ Not Found | Try Again! " << endl;
          showExit();
          newspace();
          return "fail";
        }  
    }
    return 0;
}
    
string create_account(int account_no){
      string create_username,create_password;
      println(37);
      cout << "| Laundry Store |  Register System  |" << endl;
      println(37);
      newspace();
      cout << "  Username : "; cin >> create_username;
      if(create_username == "0"){
        return "exit";
      }
      cout << "  Password : "; cin >> create_password;
      if(create_password == "0"){
        return "exit";
      }
      
      for(int account_no=0;account_no < 100;account_no++){
        if(create_username == account_folder[account_no].username){
          cout << "  Note : Username has been using! " << endl;
          showExit();
          return "fail";
        }
      }
      account_folder[account_no].username = create_username;
      account_folder[account_no].password = create_password;
      account_folder[account_no].userid = rand();
      cout << "  ☑ Register Success | Nice to see you! " << endl;
      newspace();
      using_account_no = account_no;
      return "success";
    }

    
int main(){
    float main_washing_cost,main_drying_cost;
    string func_status,machine_select,entrepreneur_status;
    int entrepreneur_mode;
    Store_Management Sriracha_store("Sriracha Laundry Store",05677777);
    Store_Management Pattaya_store("Pattaya Laundry Store ",45645767);
    Entrepreneur_Management Owner("Nonpawit",17641);
    int main_mode,account_no = 0;
    
    Sriracha_store.setCost(40,40);
    Pattaya_store.setCost(40,40);
    
    Sriracha_store.resetStatus();
    Pattaya_store.resetStatus();
    
    while(true){
        println(37);
        cout << "| Laundry Store | Management System |" << endl;
        println(37);
        newspace();
        cout << "  (1) Login Account " << endl;
        cout << "  (2) Register Account " << endl;
        cout << "  (3) Entrepreneur System " << endl;
        cout << "  (0) Exit Program " << endl;
        newspace();
        while(true){
          cout << "  System Mode > "; 
          cin >> main_mode;
          if(main_mode > 3 or main_mode < 0){
            cout << "  ☒ Not Found | Try Again!" << endl;
          }else{
            break;
          }
        }
        if(main_mode == 1){
          while(true){
            newspace();
            func_status = login_account();
            if(func_status == "success"){
              break;
            }else if(func_status == "fail"){
              continue;
            }else if(func_status == "exit"){
              newspace();
              break;
            }
          } 
        }else if(main_mode == 2){
          if(account_no < 100 and account_no >= 0){
            while(true){
                newspace();
                func_status = create_account(account_no);
                if(func_status == "success"){
                    account_no++;
                    break;
                }else if(func_status == "fail"){
                    continue;
                }else if(func_status == "exit"){
                    newspace();
                    break;
                }
            } 
          }else{
                cout << "  Note : ERROR#!7 | Full Memory!  " << endl;
                newspace();
          } 
        }else if(main_mode == 3){
            Owner.setKeys("9");
            while(true){
                newspace();
                entrepreneur_status = Owner.loginSystem();
                if(entrepreneur_status == "success"){
                    while(true){
                        println(37);
                        cout << "| Laundry Store | Entrepreneur Mode |" << endl;
                        println(37);
                        newspace();
                        cout << "  (1) Show User Account " << endl;
                        cout << "  (2) Edit Cost " << endl;
                        cout << "  (0) Exit mode " << endl;
                        newspace();
                        cout << "  System Mode > "; cin >> entrepreneur_mode;
                        newspace();
                        if(entrepreneur_mode == 1){
                            newspace();
                            Owner.showMember(account_no);
                        }else if(entrepreneur_mode == 2){
                            newspace();
                            main_washing_cost,main_drying_cost = Owner.editCost();
                            Pattaya_store.setCost(main_washing_cost,main_drying_cost);
                            Sriracha_store.setCost(main_washing_cost,main_drying_cost);
                        }else if(entrepreneur_mode == 0){
                            func_status = "fail";
                            break;
                        }
                    }
                    break;
                }else if(entrepreneur_status == "fail"){
                    cout << "  ☒ Keys Incorrect | Try Again! " << endl;
                  continue;
                }else if(entrepreneur_status == "exit"){
                  newspace();
                  func_status = "fail";
                  break;
                } 
            }
        }else if(main_mode == 0){
            break;
        }
        if(func_status == "success"){
            println(37);
            cout << "|  Laundry Store | Location Store   |" << endl;
            println(37);
            newspace();
            cout << "  (1) Sriracha Campus Store " << endl;
            cout << "  (2) Pattaya Beach Store " << endl;
            showExit();
            newspace();
            cout << "  System Mode > "; cin >> main_mode;
            newspace();
            if(main_mode == 1){
                while(true){
                    newspace();
                    Sriracha_store.showThumbnil();
                    Sriracha_store.showWash_Machine();
                    Sriracha_store.showDry_Machine();
                    newspace();
                    showExit();
                    cout << "  Machine Select > "; cin >> machine_select;
                    if(machine_select == "0"){
                        newspace();
                        break;
                    }else{
                        string func_status = Sriracha_store.calculate_Price(machine_select);
                        if(func_status == "success"){
                            break;
                        }
                    }
                }
            }else if(main_mode == 2){
                while(true){
                    newspace();
                    Pattaya_store.showThumbnil();
                    Pattaya_store.showWash_Machine();
                    Pattaya_store.showDry_Machine();
                    newspace();
                    showExit();
                    cout << "  Machine Select > "; cin >> machine_select;
                    if(machine_select == "0"){
                        newspace();
                        break;
                    }else{
                        string func_status = Pattaya_store.calculate_Price(machine_select);
                        if(func_status == "success"){
                            break;
                        }
                    }
                }
            }
        }
    }
}