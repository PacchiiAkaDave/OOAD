

#include <iostream>
#include <memory>
#include "FangDenHut.h"

int main()
{
    std::unique_ptr<FangDenHut> fDH = std::make_unique<FangDenHut>();
    fDH->starteSpiel(3);
}

