#include <boost/asio.hpp>
#include <iostream>
#include <filesystem>
#include <thread>
#include <vector>
#include <stdexcept>

using namespace boost::asio;
using namespace std;

#define DEFAULT_BAUD_RATE 9600
#define DEFAULT_PORT "/dev/ttyUSB0"

// 자동으로 포트를 감지하는 함수
string autoDetectPort()
{
  vector<string> potentialPorts = {"/dev/ttyUSB0", "/dev/ttyUSB1", "/dev/ttyS0", "/dev/tty.usbserial-140"};
  for (const auto &port : potentialPorts)
  {
    if (access(port.c_str(), F_OK) != -1)
    {
      cout << "Detected port: " << port << endl;
      return port;
    }
  }
  throw runtime_error("No available serial port detected.");
}

// 시리얼 포트를 초기화하는 함수
serial_port initializeSerialPort(io_context &io, const string &portPath, unsigned int baudRate = DEFAULT_BAUD_RATE)
{
  serial_port serial(io, portPath);
  serial.set_option(serial_port_base::baud_rate(baudRate));
  serial.set_option(serial_port_base::character_size(8));
  serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
  serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
  serial.set_option(serial_port_base::flow_control(serial_port_base::flow_control::none));
  cout << "Connected to Arduino on " << portPath << endl;
  return serial;
}

// Arduino에 메시지를 전송하는 함수
void sendMessage(serial_port &serial, const string &message)
{
  boost::asio::write(serial, boost::asio::buffer(message));
  cout << "Sent message to Arduino: " << message << endl;
}

// Arduino로부터 데이터를 읽고 즉시 출력하는 함수 (비동기 방식)
void readFromArduino(serial_port &serial)
{
  try
  {
    char c;
    while (true)
    {
      // 1바이트씩 읽고 바로 출력
      boost::asio::read(serial, boost::asio::buffer(&c, 1));
      cout << c << flush; // 바로 출력 (버퍼 강제 플러시)
    }
  }
  catch (const exception &e)
  {
    cerr << "Error while reading from Arduino: " << e.what() << endl;
  }
}

int boostAsioTest()
{
  try
  {
    // Boost.Asio IO 컨텍스트 생성
    io_context io;

    // 자동으로 시리얼 포트를 감지
    string portPath = autoDetectPort();

    // 시리얼 포트를 초기화
    serial_port serial = initializeSerialPort(io, portPath);

    // Arduino에 메시지 전송
    sendMessage(serial, "Hello, Arduino!\n");

    // Arduino로부터 데이터 수신 및 즉시 출력
    readFromArduino(serial);
  }
  catch (const exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}