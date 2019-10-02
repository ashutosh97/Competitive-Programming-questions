#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
  if (auto f = dynamic_cast<Fireball*>(spell)) {
      f->revealFirepower();
  }
  else if (auto f = dynamic_cast<Frostbite*>(spell)) {
      f->revealFrostpower();
  }
  else if (auto f = dynamic_cast<Thunderstorm*>(spell)) {
      f->revealThunderpower();
  }
  else if (auto f = dynamic_cast<Waterbolt*>(spell)) {
      f->revealWaterpower();
  }
  else {
    auto find = [](const string& A, const string& B) -> int
    {
        std::vector<std::vector<int>> LCS(A.length() + 1);        
        for (int i = 0; i < LCS.size(); i++)
            LCS[i].resize(B.length() + 1);
            
       for (int i = 1; i <= A.length(); i++) {
         for (int j = 1; j <= B.length(); j++) {
            if (A[i - 1] == B[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
       }
       return LCS[A.length()][B.length()];
    };

    string s1 = spell->revealScrollName();
    string s2 = SpellJournal::read();
    int len = 0;
    if (s1.length() > 0 && s2.length() > 0)
        len = find(&s1[0], &s2[0]);
    cout << len << endl;
  }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
