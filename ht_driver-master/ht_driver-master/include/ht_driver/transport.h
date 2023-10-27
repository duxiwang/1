/*
 * @Descripttion: 
 * @version: 
 * @Author: Nova Wu
 * @Date: 2021-09-24 16:02:11
 * @LastEditors: Nova Wu
 * @LastEditTime: 2021-09-24 16:12:39
 */

#ifndef HT_DRIVER_TRANSPORT_H_
#define HT_DRIVER_TRANSPORT_H_

#include <iostream>
#include <unistd.h>
#include <inttypes.h>
#include <vector>
#include <deque>
#include <queue>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>

namespace ht_driver 
{

	typedef std::vector<uint8_t> Buffer;
	//typedef  boost::shared_ptr<Buffer> BufferPtr;

	class Transport 
	{
	public:
		Transport(std::string url) :
			comm_url_(url),
			write_buffer_(),
			read_buffer_()
		{
			ios_ = boost::make_shared<boost::asio::io_service>();
		}

		virtual Buffer ReadBuffer() = 0;

		virtual void WriteBuffer( const Buffer &data) = 0;

		inline boost::shared_ptr<boost::asio::io_service> GetIOinstace()
		{
			return ios_;
		}

		bool initialize_ok()
		{
			return initialize_ok_;
		}

	protected:
		// for communication location
		std::string comm_url_;
		std::queue<Buffer> write_buffer_;
		std::queue<Buffer> read_buffer_;
		bool initialize_ok_;

		// for boost asio service
		boost::shared_ptr<boost::asio::io_service> ios_;
	};

}



#endif /* TRANSPORT_BASE_H_ */