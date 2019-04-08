#include <iostream>
#include <helpers.cpp>
#include <xserial.cpp>

using namespace xserial;

int main() 
{
    // инициализируем доступный COM порт, без проверки бита четности, с 8-мью битами данных и одним стоп битом.
    unsigned int baudRate = 9600; // скорость порта //14400
    const int dataBits = 8; // длина данных

    std::cout  << xserial::ComPort::COM_PORT_NOPARITY;
    std::cout  << xserial::ComPort::COM_PORT_ONESTOPBIT;

    xserial::ComPort serial(3);

    if (!serial.getStateComPort()) { // Если порт не открылся
        std::cout  << "\nError: com port is not open for baud rate: " << baudRate << std::endl;
        return 0;
    }

    // выводим список доступных портов
    serial.printListSerialPorts();

    // получаем текст до символа \n
    std::cout  << "Test getLine()..." << std::endl;
    serial << "Test 1\n";
    std::cout  << serial.getLine() << std::endl;

    // проверяем функцию проверки количества принятых байт
    std::cout  << "Test bytesToRead()..." << std::endl;
    serial.print("Test 2\n");
    int k = serial.bytesToRead();
    std::cout  << "bytes to read = " << k << std::endl;

    while (k < 6) 
    {
        k = serial.bytesToRead();
    }

    std::cout  << "bytes to read = " << k << std::endl;

    // проверяем функцию чтения
    char data[512];
    std::cout  << "Test read()..." << std::endl;
    serial.read(data, 7);
    std::cout  << data << std::endl;

    // проверяем функцию чтения слова
    serial.print("Bla Bla Bla\n");
    std::cout  << "Test getWord(), print Bla Bla Bla" << std::endl;
    std::cout  << "Word 1: " << serial.getWord() << std::endl;
    std::cout  << "Word 2: " << serial.getWord() << std::endl;
    std::cout  << "Word 3: " << serial.getWord() << std::endl;

    return 0;
}
