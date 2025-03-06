//-------------------------------------------------
// 2025. STL 3.6                              1w 2d
//-------------------------------------------------
// 강의소개 : 한 학기 강의를 저장할 수 있는 save 기능
// 
// Release  x64
// 프로젝트 -> 속성 -> c++ 표준 최신으로 - std::c++latest
// c/c++ 에서 sdl검사 아니요로
//-------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void save(std::string_view);

int main()
{
    std::cout << "2025 STL 시작" << std::endl;

    save("main.cpp");
    return 0;
}


void save(std::string_view fileName) {
    // 파일 fileName을 연다.
    std::ifstream in{ fileName.data() };
    if (not in) { // -> ! 말고 not 쓰기;;ㅋㅋㅋ
        std::cout << fileName << "을 열 수 없습니다." << std::endl;
        exit(0);
    }

    // 저장했음을 화면에 출력하자.

    auto size = std::filesystem::file_size(fileName);
    std::cout << fileName << " - " << size << "byte를 저장 하였습니다." << std::endl;

    // 저장할 파일도 연다.
    std::ofstream out{ "2025 1학기 STL 화78목23 강의 저장.txt", std::ios::app };


    // 읽을 파일의 내용을 읽어서 저장할 파일에 덧붙인다.

    std::vector<char> v(size);         // 컨테이너의 메모리를 확보한다.
    std::copy(std::istreambuf_iterator{ in }, {}, v.begin());   // 파일을 메모리로
    std::copy(v.begin(), v.end(), std::ostreambuf_iterator{ out }); // 메모리를 파일로
}


