#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

int main() {
    // ASCIIファイルからメールアドレスを読み込む
    std::ifstream file("emails.txt");
    std::vector<std::string> emails;
    std::string line;

    // ファイルが開けたかどうかを確認
    if (file.is_open()) {
        // ファイルから1行ずつ読み込む
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string email;
            // カンマ区切りでメールアドレスを分割してベクターに追加
            while (std::getline(iss, email, ',')) {
                emails.push_back(email);
            }
        }
        file.close(); // ファイルを閉じる
    }
    else {
        // ファイルが開けなかった場合のエラーメッセージ
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    // メールアドレスを学籍番号順にソート
    std::sort(emails.begin(), emails.end());

    // ソートされたメールアドレスを出力
    std::cout << "Sorted emails:" << std::endl;
    for (const auto& email : emails) {
        std::cout << email << std::endl;
    }

    return 0;
}
