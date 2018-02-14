/*
 * AVRSimulator.h
 *
 *  Created on: 14 févr. 2018
 *      Author: elominp
 */

#ifndef AVRSIMULATOR_H_
# define AVRSIMULATOR_H_

# include <sim_avr.h>
# include <sim_hex.h>
# include <sim_gdb.h>
# include <iostream>
# include <cstdint>
# include <cstddef>
# include "uart_pty.h"

# ifndef DEFAULT_MCU
#  define DEFAULT_MCU   ("atmega328p")
# endif /* DEFAULT_MCU */

# ifndef DEFAULT_F_CPU
#  define DEFAULT_F_CPU (16000000)
# endif /* DEFAULT_F_CPU */

namespace athome {
    namespace utils {

        class AVRSimulator {
        public:
            AVRSimulator(
                std::string,
                std::string = DEFAULT_MCU,
                uint32_t = DEFAULT_F_CPU
            );
            virtual ~AVRSimulator();

            void init();
            void run();

        protected:
            virtual void _init_avr();
            virtual void _init_firmware();
            virtual void _init_uart();

            virtual void _deinit_avr();
            virtual void _deinit_firmware() {};
            virtual void _deinit_uart();

        private:
            std::string     _firmwarePath;
            std::string     _mcuName;
            uint32_t        _fCPU;
            avr_t           *_avr;
            uart_pty_t      _uart_pty;

        private:
            static size_t   _instancesCount;
        };

    } /* namespace utils */
} /* namespace athome */

#endif /* AVRSIMULATOR_H_ */
