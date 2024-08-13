// GlobalManager.h
#ifndef GLOBALMANAGER_H
#define GLOBALMANAGER_H

#include "MemberManager.h"

class GlobalManager {
public:
    static GlobalManager& getInstance();

    MemberManager* getMemberManager() const;
    void setMemberManager(MemberManager* manager);

private:
    GlobalManager();
    ~GlobalManager();
    GlobalManager(const GlobalManager&) = delete;
    GlobalManager& operator=(const GlobalManager&) = delete;

    MemberManager* memberManager;
};

#endif // GLOBALMANAGER_H
