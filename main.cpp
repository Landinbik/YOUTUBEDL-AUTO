#include <iostream>
#include <Windows.h>

std::string get_clipboard_text() {
    if (OpenClipboard(NULL)) {
        HANDLE handle = GetClipboardData(CF_TEXT);

        char* clip_text = static_cast<char*>(GlobalLock(handle));
        if (clip_text == nullptr)
            return 0;

        GlobalUnlock(handle);
        CloseClipboard();

        return std::string(clip_text);
    }
}

int main() {
    while (true) {
        auto clipboard = get_clipboard_text();

        if (clipboard.find("youtube") != std::string::npos) {
            system(std::string("youtube-dl -f bestvideo+bestaudio --merge-output-format mp4 " + clipboard).c_str());
        }

        Sleep(20);
    }

    std::cin.get();
return ;
}
