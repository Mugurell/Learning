template <std::size_t H, std::size_t W>
inline Screen<H, W>& Screen<H, W>::move_at(pos l, pos w)
{
    pos row = width * l;
    cursor = row + w;

    return this;
}


template<std::size_t T1, std::size_t T2>
std::ostream& operator<<(std::ostream &os, const Screen<T1, T2> &screen)
{
    size_t char_count = 0, h = screen.height;
    while (h-- > 0)
    {
        size_t w = screen.width;
        while (w-- > 0)
        {
            os << screen.contents.at(char_count++);
        }
        std::cout << '\n';
    }

    return os;
}


template<std::size_t T1, std::size_t T2>
std::istream& operator>>(std::istream &is, Screen<T1, T2> &new_screen)
{
    char ch;
    is >> ch;
    std::string temp(new_screen.height * new_screen.width, ch);
    new_screen.contents = temp;

    return is;
}