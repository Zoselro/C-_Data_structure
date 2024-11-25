#include<iostream>
#include<boost/beast.hpp>
#include<boost/asio.hpp>

namespace beast = boost::beast;
namespace http = beast::http;    // HTTP에 대한 Boost.Beast 별칭
namespace net = boost::asio;     // 네트워크 기능을 위한 Boost.Asio 네임스페이스
using tcp = net::ip::tcp;        // TCP 소켓을 위한 타입 정의

int main() {
    return 0;
}