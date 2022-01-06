#include<ros/ros.h>
#include<move_base_msgs/MoveBaseAction.h>
#include<actionlib/client/simple_action_client.h>

//
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv)
{
 ros::init(argc, argv, "move_bot");
 
 MoveBaseClient ac("move_base", true);
 
 while(!ac.waitForServer(ros::Duration(1.0)))
 { ROS_INFO("Waiting for the move_base action server to come up");
 }
 
 move_base_msgs::MoveBaseGoal goal;
 
 goal.target_pose.header.frame_id = "map";
 goal.target_pose.header.stamp = ros::Time::now();
 
 float goals[4][3] = { {10, 3, 0.8727},{-10, 3, 0.8727}, {-10, -3, 0.8727}, {10, -3, 0.8727} };
 for (int i=0; i<(i+1); i++){
 if(i<4){
 goal.target_pose.pose.position.x = goals[i][0];
 goal.target_pose.pose.position.y = goals[i][1];
 goal.target_pose.pose.orientation.w = goals[i][2];
 
 ROS_INFO("Sending goal");
 ac.sendGoal(goal);
 
 ac.waitForResult();
 
 ros::Duration(1.0).sleep();
 }
  else
	 i = 0;
 }
}