#include <iostream>
#include <string>

using namespace std;

class Screen {
    public:
        typedef string::size_type pos;
        Screen () = default;
        Screen (pos wd, pos ht, char c) : width(wd), height(ht), contents(wd * ht, c) {}
        char get() const {
            return contents[cursor];
        }
        char get(pos r, pos c) const {
            return contents[r + width + c];
        }
        Screen & move(pos r, pos c) {
            cursor = r * width + c;
            return *this;
        }
        Screen & set(pos r, pos c, char ch) {
            contents[r * width + c] = ch;
            return *this;
        }
        Screen & set(char c) {
            contents[cursor] = c;
            return *this;
        }
        Screen & display() {
            do_display();
            return *this;
        }
        const Screen & display() const {
            do_display();
            return *this;
        }
        void do_display() const {
            for (pos i = 0; i < height; i++) {
                for (pos j = 0; j < width; j++)
                    cout << contents[i * width + j];
                cout << endl;
            }
            cout << endl;
        }
    private:
        pos height = 0;
        pos cursor = 0;
        pos width = 0;
        string contents;
};

int main()
{
    Screen  scr(10, 5, '.');
    scr.display();
    scr.set(1, 3, 'O').display();
}
