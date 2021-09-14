//
//  main.cpp
//  test1
//
//  Created by 井塚雄喜 on 2021/09/13.
//

//
//  main.cpp
//  test3
//
//  Created by 井塚雄喜 on 2021/09/13.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ファイル読み込み関数
void ReadFile(const string filename, vector<string>& words){
    ifstream read_file_stream(filename, ios::in);
    // ファイルオープン失敗の時の処理
    if (!read_file_stream) {
        cout << "ファイルオープン失敗" << endl;
    }
    string word = "";
    while (getline(read_file_stream, word)) {
        words.push_back(word);
    }
    cout << words.size() << endl;
}

// ファイル書き込み関数
void WriteFile(const string filename, vector<string>& words){
    ofstream write_file_stream(filename);
    // ファイルオープン失敗の時の処理
    if (!write_file_stream) {
        cout << "ファイルオープン失敗" << endl;
    }
    int num_words = (int)words.size();
    for (int i = 0; i < num_words; i++) {
        write_file_stream << words[i] << endl;
    }
    write_file_stream.close();
}

int main(int argc, const char* argv[]) {
    vector<string> words;
    ReadFile("word.txt", words);
    WriteFile("Output.txt", words);
    return 0;
}