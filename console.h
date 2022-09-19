#pragma once

#include "common.h"
#include "repo.h"

struct Console
{
   int run();

protected:
    std::optional<std::string> readInput();

private:
   cpp20::Repository m_repo;
};


