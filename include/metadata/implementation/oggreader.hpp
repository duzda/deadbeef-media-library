#pragma once

#include "reader.hpp"

class OggReader : public Reader {
public:
    OggReader();
    ~OggReader();

    Glib::RefPtr<Gdk::Pixbuf> getImage(std::filesystem::path path, int size);
    TagLib::ByteVector* getData(std::filesystem::path path);
private:
};