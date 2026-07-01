#include "Service.h"
#include <algorithm>

std::vector<Idea*> Service::getIdeas()
{
    std::vector<Idea*> res = this->repo.getIdeas();
    
    std::sort(res.begin(), res.end(), [](Idea* a, Idea* b) {
        return a->getAct() < b->getAct();
        });
    return res;
}
