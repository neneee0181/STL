#include "save.h"

void save(std::string_view fileName) {
    // ���� fileName�� ����.
    std::ifstream in{ fileName.data() };
    if (not in) { // -> ! ���� not ����;;������
        std::cout << fileName << "�� �� �� �����ϴ�." << std::endl;
        exit(0);
    }

    // ���������� ȭ�鿡 �������.
    std::cout << fileName << " - " << std::filesystem::file_size(fileName)
        << "byte�� ���� �Ͽ����ϴ�." << std::endl;

    // ������ ���ϵ� ����.
    std::ofstream out{ "2025 1�б� STL ȭ78��23 ���� ����.txt", std::ios::app };

    // ������ �ð��� ���Ͽ� �������.
     // ���� UTC �ð� ��������
    auto now = std::chrono::system_clock::now();
    std::time_t utc = std::chrono::system_clock::to_time_t(now);

    // ������ ������ ���� �ð� ��ȯ
    std::tm localTime;
    localtime_s(&localTime, &utc); // Windows ȯ�� (POSIX�� localtime_r ���)

    std::locale oldLocale = std::cout.getloc();

    // ��� ��Ʈ���� ��Ķ�� �ѱ���� ����
    std::locale loc("ko_KR.utf8"); // �ý��ۿ��� �����Ǵ��� Ȯ�� �ʿ�
    std::cout.imbue(loc);

    out << '\n\n';
    out << "========================================" << '\n';
    out << "���� �ð� : " << std::put_time(&localTime, "%c %A") << '\n';
    out << "========================================" << '\n';
    out << '\n';

    out.imbue(oldLocale); // out ������ ������� �������´�.

    // ���� ������ ������ �о ������ ���Ͽ� �����δ�.
    std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });   // ������ �޸𸮷�
}


