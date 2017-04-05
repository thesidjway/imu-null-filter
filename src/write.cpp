    #include <rosbag/bag.h>
    #include <std_msgs/Int32.h>
    #include <std_msgs/String.h>

int main(int argc, char *argv[])
{
    rosbag::Bag bag;
    bag.open(argv[1], rosbag::bagmode::Write);

    std_msgs::String str;
    str.data = std::string("foo");

    std_msgs::Int32 i;
    i.data = 42;

    bag.write("chatter", ros::Time::now(), str);
    bag.write("numbers", ros::Time::now(), i);

    bag.close();
}