#include <rclcpp/rclcpp.hpp>
#include <test_cpp_msgs/msg/test.hpp>

class TestSub : public rclcpp::Node
{
public:
	TestSub()
		: Node("test_sub_cpp")
	{
		_sub = this->create_subscription<test_cpp_msgs::msg::Test>(
			"/test_sub",
			10,
			[this](test_cpp_msgs::msg::Test::ConstSharedPtr msg)
			{
				RCLCPP_INFO(
					this->get_logger(),
					"Recieved msg with header %s",
					msg->header.frame_id.c_str()
				);
			}
			);
	}
	rclcpp::Subscription<test_cpp_msgs::msg::Test>::SharedPtr _sub;
};


int main(int argc, char** argv)
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<TestSub>();
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}