#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "CAN.hpp"
#include "zenoh.hxx"
#include <arpa/inet.h>

using namespace zenoh;

class Signals {

    private:
        CAN* canBus;
        Session m_session;
        Publisher m_pubSpeed;

    public:
        Signals();
        ~Signals();

        void init(const std::string& canDevice);
        void run();


};

