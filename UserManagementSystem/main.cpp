#include <bits/stdc++.h>
using namespace std;

// User Data
struct user {
    char role[20]; // 직접적인 초기화 제한, 생성자 내부에서 초기화
    char name[20];
    int age;
    int phone;

    user() {strcpy(role, "user");}
};

// Register
user userRegister() {
    user newUser;

    // 사용자 정보 입력
    cout << "이름을 입력 하세요: ";
    cin.getline(newUser.name, 20);
    cout << "\n";

    cout << "나이를 입력 하세요: ";
    cin >> newUser.age;
    cout << "\n";

    cout << "전화번호를 입력 하세요: ";
    cin >> newUser.phone;
    cout << "\n";

    // 유효성 검사 추후 생성

    // 파일 시스템에 저장 (바이너리 모드로 파일 열기)
    ofstream outFile("UserManagementSystem/user.dat", ios::binary | ios::app);
    if (!outFile) {
        cerr << "파일을 열 수 없습니다." << "\n";
        exit(1);
    }

    // 입력된 유저 정보를 파일에 쓰기
    outFile.write(reinterpret_cast<char*>(&newUser), sizeof(user));
    outFile.close(); // 파일 닫기

    cout << "등록이 완료되었습니다." << "\n";
    return newUser;
}

// Save Data (File System)

int main() {
    userRegister();
    return 0;
}