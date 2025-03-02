    #include <rosbag/bag.h>
    #include <rosbag/view.h>
    #include <std_msgs/Int32.h>
    #include <std_msgs/String.h>
    #include <boost/foreach.hpp>

    #define foreach BOOST_FOREACH

int main(int argc, char *argv[])
{

    rosbag::Bag bag;
    bag.open(argv[1], rosbag::bagmode::Read);

    std::vector<std::string> topics;
    topics.push_back(std::string(argv[2]));

    rosbag::View view(bag, rosbag::TopicQuery(topics));

    foreach(rosbag::MessageInstance const m, view)
    {
        std_msgs::String::ConstPtr s = m.instantiate<std_msgs::String>();
        if (s != NULL)
            std::cout << s->data << std::endl;

        std_msgs::Int32::ConstPtr i = m.instantiate<std_msgs::Int32>();
        if (i != NULL)
            std::cout << i->data << std::endl;
    }

    bag.close();
    return 0;
}