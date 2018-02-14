/*
 * AVRSimulator.cpp
 *
 *  Created on: 14 févr. 2018
 *      Author: elominp
 */

#include <stdexcept>
#include <cstring>
#include <cstdlib>
#include "AVRSimulator.h"

namespace athome {
    namespace utils {

        AVRSimulator::AVRSimulator(
            std::string firmwarePath,
            std::string mcuName,
            uint32_t fCPU
        ):
            _firmwarePath(firmwarePath),
            _mcuName(mcuName),
            _fCPU(fCPU),
            _avr(nullptr) {
        }

        AVRSimulator::~AVRSimulator() {
            if (_avr != nullptr) {
                delete _avr;
            }
        }

        void AVRSimulator::init() {
            _init_avr();
            _init_firmware();
        }

        void AVRSimulator::run() {
            while (1) {
                int state = avr_run(_avr);
                if (state == cpu_Done || state == cpu_Crashed) {
                    break;
                }
            }
        }

        void AVRSimulator::_init_avr() {
            _avr = avr_make_mcu_by_name(_mcuName);
            if (_avr == nullptr) {
                throw std::runtime_error("Unable to allocate AVR mcu");
            }
            avr_init(_avr);
            _avr->frequency = _fCPU;
            _avr->log = 1;
        }

        void AVRSimulator::_init_firmware() {
            uint32_t    base, size;
            uint8_t     *firmware;

            firmware = read_ihex_file(_firmwarePath, &size, &base);
            if (firmware == nullptr) {
                throw std::runtime_error("Unable to load firmware");
            }
            memcpy(_avr->flash + base, firmware, size);
            delete firmware;
            _avr->pc = base;
            _avr->codeend = _avr->flashend;
        }

        void AVRSimulator::_init_uart() {
            if (_instancesCount > 9) {
                throw std::runtime_error("Unable to init simulator, maximum UART number exceeded");
            }
            uart_pty_init(_avr, &_uart_pty);
            uart_pty_connect(&_uart_pty, '0' + _instancesCount);
        }

        size_t AVRSimulator::_instancesCount = 0;

    } /* namespace utils */
} /* namespace athome */
