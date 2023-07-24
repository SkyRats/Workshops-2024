#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <skyrats_cpp/kbhit.h>


int main(int argc, char** argv)
{
    ros::init(argc, argv, "skyrats_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);

    geometry_msgs::Twist move;

    while(ros::ok){
        if(kbhit()){
            char key = getchar();
            switch (key)
            {
                case 'w':
                    move.linear.x = 0.2; // Mude os valores como quiser! 
                    move.angular.z = 0.0;
                    pub.publish(move);
                    break;
                case 'x':
                    move.linear.x = -0.2;
                    move.angular.z = 0.0;
                    pub.publish(move);
                    break;
                case 'a':
                    move.linear.x = 0.0;
                    move.angular.z = 0.26;
                    pub.publish(move);
                    break;

                case 's':
                    move.linear.x = 0.0;
                    move.angular.z = 0.0;
                    pub.publish(move);
                    break;
                case 'p':
                    return 0;
                    break;

                default:
                    break;

            }
        }
    }

    return 0;
}


