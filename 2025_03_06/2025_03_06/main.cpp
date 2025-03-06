//-------------------------------------------------
// 2025. STL 3.6                              1w 2d
//-------------------------------------------------
// ���ǼҰ� : �� �б� ���Ǹ� ������ �� �ִ� save ���
// 
// Release  x64
// ������Ʈ -> �Ӽ� -> c++ ǥ�� �ֽ����� - std::c++latest
// c/c++ ���� sdl�˻� �ƴϿ��
//-------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void save(std::string_view);

int main()
{
    std::cout << "2025 STL ����" << std::endl;

    save("main.cpp");
    return 0;
}


void save(std::string_view fileName) {
    // ���� fileName�� ����.
    std::ifstream in{ fileName.data() };
    if (not in) { // -> ! ���� not ����;;������
        std::cout << fileName << "�� �� �� �����ϴ�." << std::endl;
        exit(0);
    }

    // ���������� ȭ�鿡 �������.

    auto size = std::filesystem::file_size(fileName);
    std::cout << fileName << " - " << size << "byte�� ���� �Ͽ����ϴ�." << std::endl;

    // ������ ���ϵ� ����.
    std::ofstream out{ "2025 1�б� STL ȭ78��23 ���� ����.txt", std::ios::app };


    // ���� ������ ������ �о ������ ���Ͽ� �����δ�.

    std::vector<char> v(size);         // �����̳��� �޸𸮸� Ȯ���Ѵ�.
    std::copy(std::istreambuf_iterator{ in }, {}, v.begin());   // ������ �޸𸮷�
    std::copy(v.begin(), v.end(), std::ostreambuf_iterator{ out }); // �޸𸮸� ���Ϸ�
}


