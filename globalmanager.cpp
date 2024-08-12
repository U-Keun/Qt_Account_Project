// GlobalManager.cpp
#include "GlobalManager.h"

GlobalManager::GlobalManager() : memberManager(nullptr) {
    qDebug("글로벌 매니저 생성");
}

GlobalManager::~GlobalManager() {
    qDebug("글로벌 매니저 소멸");
    delete memberManager;
}

GlobalManager& GlobalManager::getInstance() {
    static GlobalManager instance;
    return instance;
}

MemberManager* GlobalManager::getMemberManager() const {
    return memberManager;
}

void GlobalManager::setMemberManager(MemberManager* manager) {
    memberManager = manager;
}
