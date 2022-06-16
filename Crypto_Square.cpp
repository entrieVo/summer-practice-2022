#include<iostream>
#include<string>
#include<cmath>
#include<vector>

//* Implement the classic method for composing secret messages called a square code.
//* Given an English text, output the encoded version of that text.
//* 
//* First, the input is normalized: the spaces and punctuation are removed from the
//* English text and the message is downcased. Then, the normalized characters are
//* broken into rows. These rows can be regarded as forming a rectangle when printed
//* with intervening newlines. The plaintext should be organized in to a rectangle.
//* The size of the rectangle (r x c) should be decided by the length of the message,
//* such that c >= r and c - r <= 1, where c is the number of columns and r is the
//* number of rows. The coded mesy7sage is obtained by reading down the columns going
//* left to right. Output the encoded text in chunks that fill perfect rectangles
//* (r X c), with c chunks of r length, separated by spaces. For phrases that are n
//* characters short of the perfect rectangle, pad each of the last n chunks with a
//* single trailing space.

using namespace std;

class CryptoSquare {

    string ciphertext;              // a variable to store string ciphers
    private:string sentence;        // input text
    vector<string> encodedText;

    int r;  // the number of rows
    int c;  // the number of columns

    public:CryptoSquare(string sentence) {
        this->sentence = sentence;
        ciphertext = "";
        r = c = 0;

     Encode();
    }

    private:string Encode() {

        TextNormalize();

        c = ceil(sqrt(ciphertext.size()));
        r = (c * c < ciphertext.size()) ? c : floor(sqrt(ciphertext.size()));

        TextNormalize(RectangleOrganize(c));
        encodedText = RectangleOrganize(r, true);

     return ciphertext;
    }

    string TextNormalize() {

        const int difference = abs('a' - 'A');
        for(size_t i = 0; i < sentence.size(); i++) {

            if(sentence[i] >= 'a' && sentence[i] <= 'z')
            ciphertext += sentence[i];

            else if(sentence[i] >= 'A' && sentence[i] <= 'Z')
            ciphertext = sentence[i] + difference;
        }
     return ciphertext;
    }
    string TextNormalize(vector<string> strRectangle) {

        ciphertext = "";
        //> assemble the elements in order from top to bottom from left to right
        for(size_t i = 0; i < c; i++) {
            for(size_t j = 0; j < r; j++) {
                const char symbol = strRectangle[j][i];
                if(symbol != ' ') ciphertext += symbol;
            }
        }
     return ciphertext;
    }
    vector<string> RectangleOrganize(size_t length, bool spacesFill = false) {

        // the number of words from the end, containing one space, needed to create an even rectangle
        const int spaces = r * c - ciphertext.size();

        vector<string> strRectangle;
        for(size_t i = 0; i < ciphertext.size(); i += length) {

            //> reduce the length when the limit is reached
            if (spacesFill && c - strRectangle.size() == spaces) length--;
            string word = ciphertext.substr(i, length);
            word.resize(spacesFill && c - strRectangle.size() <= spaces ? length + 1 : length, ' ');

            strRectangle.push_back(word);
        }
     return strRectangle;
    }

    public:string GetEncodedTextString() {

        ciphertext = "";
        for(auto it : encodedText) ciphertext += it + ' ';
     return ciphertext;
    }
    vector<string> GetEncodedRectangle()
    { return encodedText; }
};

int main() {

    cout << "Input a sentence:\n";
    string sentence; getline(cin, sentence);

    CryptoSquare cipher(sentence);
    cout << "\nEncoded text:\n";
    vector<string> EncodedText = cipher.GetEncodedRectangle();
    for(auto it : EncodedText) cout << it << endl;
}