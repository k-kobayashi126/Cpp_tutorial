#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Task
{
    private:
        string title;
        bool isDone = false;
    public:
        string getTitle() const{
            return title;
        }
        void setTitle(string str){
            this->title = str;
        }
        bool getIsDone() const{
            return isDone;
        }
        void reverseIsDone(){
            isDone = !isDone;
        }
};

int main()
{
    vector<Task> todo;
    int selectNum = 1;
    string title;
    int index;

    while (selectNum != 0) {
        cout << "何をしますか？（1:タスク追加, 2:タスク表示, 3:変更する, 0:終了）" << endl << "→";
        cin >> selectNum;

        if (selectNum == 1) {
            cout << "タスクを追加します。タイトルを入力してください。" << endl << "→";
            cin >> title;

            Task newTodo;
            newTodo.setTitle(title);
            todo.push_back(newTodo);
        } else if (selectNum == 2) {
            cout << "現在のタスク" << endl;
            for (int i=0; i<todo.size(); i++) {
                if (todo[i].getIsDone()) {
                    cout << "[x] " << todo[i].getTitle() << endl;
                } else {
                    cout << "[ ] " << todo[i].getTitle() << endl;
                }
                
            }
        } else if (selectNum == 3) {
            cout << "何番を変更にしますか？" << endl << "→";
            cin >> index;
            todo[index].reverseIsDone();
        } else if (selectNum == 0) {
            cout << "終了します" << endl;
        }
    }

    return 0;
}