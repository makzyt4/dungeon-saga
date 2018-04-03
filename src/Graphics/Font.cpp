#include "../../include/Graphics/Font.hpp"

ds::Font::Font() {
    charMap[0X20] = 0X0000000000000000LL; //   0x20
    charMap[0X21] = 0X000000FAFA000000LL; // ! 0x21
    charMap[0X22] = 0X00C0C000C0C00000LL; // " 0x22
    charMap[0X23] = 0X28FEFE28FEFE2800LL; // # 0x23
    charMap[0X24] = 0X002474D6D65C4800LL; // $ 0x24
    charMap[0X25] = 0X32566C18366A4C00LL; // % 0x25
    charMap[0X26] = 0X0C7EF29AEE5C1602LL; // & 0x26
    charMap[0X27] = 0X000020E0C0000000LL; // ' 0x27
    charMap[0X28] = 0X0000387CC6820000LL; // ( 0x28
    charMap[0X29] = 0X000082C67C380000LL; // ) 0x29
    charMap[0X2A] = 0X10547C38387C5410LL; // * 0x2a
    charMap[0X2B] = 0X0010107C7C101000LL; // + 0x2b
    charMap[0X2C] = 0X0000010706000000LL; // , 0x2c
    charMap[0X2D] = 0X0010101010101000LL; // - 0x2d
    charMap[0X2E] = 0X0000060600000000LL; // . 0x2e
    charMap[0X2F] = 0X02060C183060C080LL; // / 0x2f
    charMap[0X30] = 0X007CFE9AB2FE7C00LL; // 0 0x30
    charMap[0X31] = 0X002060FEFE000000LL; // 1 0x31
    charMap[0X32] = 0X0042C68E9AF26200LL; // 2 0x32
    charMap[0X33] = 0X0044C69292FE6C00LL; // 3 0x33
    charMap[0X34] = 0X183868C8FEFE0800LL; // 4 0x34
    charMap[0X35] = 0X00E4E6A2A2BE9C00LL; // 5 0x35
    charMap[0X36] = 0X3C7ED292929E0C00LL; // 6 0x36
    charMap[0X37] = 0X0080808E9EF0E000LL; // 7 0x37
    charMap[0X38] = 0X006CFE9292FE6C00LL; // 8 0x38
    charMap[0X39] = 0X0060F29296FC7800LL; // 9 0x39
    charMap[0X3A] = 0X0000006666000000LL; // : 0x3a
    charMap[0X3B] = 0X0000016766000000LL; // ; 0x3b
    charMap[0X3C] = 0X0010102828444400LL; // < 0x3c
    charMap[0X3D] = 0X0028282828282800LL; // = 0x3d
    charMap[0X3E] = 0X0044442828101000LL; // > 0x3e
    charMap[0X3F] = 0X0040C08A9AF06000LL; // ? 0x3f
    charMap[0X40] = 0X007CC6BABACA7800LL; // @ 0x40
    charMap[0X41] = 0X007EFE9090FE7E00LL; // A 0x41
    charMap[0X42] = 0X00FEFE9292FE6C00LL; // B 0x42
    charMap[0X43] = 0X00387CC682828200LL; // C 0x43
    charMap[0X44] = 0X00FEFE82C67C3800LL; // D 0x44
    charMap[0X45] = 0X00FEFE9292828200LL; // E 0x45
    charMap[0X46] = 0X00FEFE9090808000LL; // F 0x46
    charMap[0X47] = 0X007CFE8292DE5E00LL; // G 0x47
    charMap[0X48] = 0X00FEFE1010FEFE00LL; // H 0x48
    charMap[0X49] = 0X000082FEFE820000LL; // I 0x49
    charMap[0X4A] = 0X0004060202FEFC00LL; // J 0x4a
    charMap[0X4B] = 0XFEFE10386CC68200LL; // K 0x4b
    charMap[0X4C] = 0X00FEFE0202020200LL; // L 0x4c
    charMap[0X4D] = 0XFEFE603060FEFE00LL; // M 0x4d
    charMap[0X4E] = 0XFEFE603018FEFE00LL; // N 0x4e
    charMap[0X4F] = 0X7CFE8282FE7C0000LL; // O 0x4f
    charMap[0X50] = 0X00FEFE9090F06000LL; // P 0x50
    charMap[0X51] = 0X7CFE8286FE7E0200LL; // Q 0x51
    charMap[0X52] = 0X00FEFE9098FE6600LL; // R 0x52
    charMap[0X53] = 0X0064F6B29ADE4C00LL; // S 0x53
    charMap[0X54] = 0X008080FEFE808000LL; // T 0x54
    charMap[0X55] = 0X00FCFE0202FEFC00LL; // U 0x55
    charMap[0X56] = 0X00F0FC0E0EFCF000LL; // V 0x56
    charMap[0X57] = 0XFEFE0C180CFEFE00LL; // W 0x57
    charMap[0X58] = 0X82C66C38386CC682LL; // X 0x58
    charMap[0X59] = 0X80C0603E3E60C080LL; // Y 0x59
    charMap[0X5A] = 0X868E9AB2E2C28200LL; // Z 0x5a
    charMap[0X5B] = 0X0000FEFE82820000LL; // [ 0x5b
    charMap[0X5C] = 0X80C06030180C0602LL; // \ 0x5c
    charMap[0X5D] = 0X00008282FEFE0000LL; // ] 0x5d
    charMap[0X5E] = 0X002060C0C0602000LL; // ^ 0x5e
    charMap[0X5F] = 0X0202020202020000LL; // _ 0x5f
    charMap[0X60] = 0X000000C0E0200000LL; // ` 0x60
    charMap[0X61] = 0X00042E2A2A3E1E00LL; // a 0x61
    charMap[0X62] = 0X00FEFE22223E1C00LL; // b 0x62
    charMap[0X63] = 0X001C3E2222220000LL; // c 0x63
    charMap[0X64] = 0X001C3E2222FEFE00LL; // d 0x64
    charMap[0X65] = 0X001C3E2A2A3A1800LL; // e 0x65
    charMap[0X66] = 0X00207EFEA0A00000LL; // f 0x66
    charMap[0X67] = 0X00183D25253F3E00LL; // g 0x67
    charMap[0X68] = 0X00FEFE20203E1E00LL; // h 0x68
    charMap[0X69] = 0X000000BCBE020000LL; // i 0x69
    charMap[0X6A] = 0X00010101BFBE0000LL; // j 0x6a
    charMap[0X6B] = 0X00FEFE081C362200LL; // k 0x6b
    charMap[0X6C] = 0X000000FCFE020000LL; // l 0x6c
    charMap[0X6D] = 0X3E3E3018303E1E00LL; // m 0x6d
    charMap[0X6E] = 0X003E3E20203E1E00LL; // n 0x6e
    charMap[0X6F] = 0X001C3E22223E1C00LL; // o 0x6f
    charMap[0X70] = 0X003F3F24243C1800LL; // p 0x70
    charMap[0X71] = 0X00183C24243F3F00LL; // q 0x71
    charMap[0X72] = 0X003E3E2020301000LL; // r 0x72
    charMap[0X73] = 0X00123A2A2A2E0400LL; // s 0x73
    charMap[0X74] = 0X0020FCFE22220000LL; // t 0x74
    charMap[0X75] = 0X003C3E02023E3E00LL; // u 0x75
    charMap[0X76] = 0X00383C06063C3800LL; // v 0x76
    charMap[0X77] = 0X3C3E020C023E3C00LL; // w 0x77
    charMap[0X78] = 0X22361C081C362200LL; // x 0x78
    charMap[0X79] = 0X00383D07063C3800LL; // y 0x79
    charMap[0X7A] = 0X0022262E3A322200LL; // z 0x7a
    charMap[0X7B] = 0X0000107CEE820000LL; // { 0x7b
    charMap[0X7C] = 0X000000FEFE000000LL; // | 0x7c
    charMap[0X7D] = 0X000082EE7C100000LL; // } 0x7d
    charMap[0X7E] = 0X2060406020604000LL; // } 0x7e
}

std::uint64_t ds::Font::getCharacter(char c) {
    std::map<char, std::uint64_t>::iterator it = charMap.find(c);

    if (it == charMap.end()) {
        return 0LL;
    }

    return it->second;
}

void ds::Font::drawCharacter(sf::RenderWindow* window, char c,
                             const sf::Vector2i& position,
                             const std::uint8_t& size, const sf::Color& color) {
    uint64_t ch = getCharacter(c);
    int x = position.x;
    int y = position.y;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (ch & (1LL << ((7 - j) + 8 * (7 - i)))) {
                sf::RectangleShape rect;
                rect.setPosition(x + i * size, y + j * size);
                rect.setSize(sf::Vector2f(size, size));
                rect.setFillColor(color);
                window->draw(rect);
            }
        }
    }
}
