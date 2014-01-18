
#include <ros/ros.h>
#include <tf/tf.h>
#include <visualization_msgs/Marker.h>
#include "fiducials_rviz.h"

typedef struct rvizData {
  ros::NodeHandle *nh;
  ros::Publisher *publisher;
} rvizData_struct;

#define NAMESPACE "fiducials"
#define TOPIC "visualization_marker"

void* initRviz(int argc, char **argv, char *nodeName)
{
  rvizData_struct *rd = (rvizData_struct*)malloc(sizeof(rvizData_struct));

  ros::init(argc, argv, nodeName);

  rd->nh = new ros::NodeHandle();
  static ros::Publisher publisher =
    rd->nh->advertise<visualization_msgs::Marker>(TOPIC, 1);
  rd->publisher = &publisher; 

  return rd;
}

int isOK()
{
  return ros::ok();
}

void sendMarker(void* rd, const char *frame, int id, double x, double y,
    double z, double twist, double dx, double dy, double dz)
{
    rvizData_struct* rds = (rvizData_struct*)rd;
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = frame;
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = NAMESPACE;
    marker.id = id;
    marker.type = visualization_msgs::Marker::CUBE;

    // Set the marker action.  Options are ADD and DELETE
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = z;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = dx;
    marker.scale.y = dy;
    marker.scale.z = dz;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    rds->publisher->publish(marker);
}

void sendArrow(void* rd, const char *frame, int id, double x, double y,
    double z, double twist, double dx, double dy, double dz, double bearing)
{
    rvizData_struct* rds = (rvizData_struct*)rd;
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = frame;
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = NAMESPACE;
    marker.id = id;
    marker.type = visualization_msgs::Marker::ARROW;

    // Set the marker action.  Options are ADD and DELETE
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = z;
    marker.pose.orientation = tf::createQuaternionMsgFromYaw(bearing);

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = dx;
    marker.scale.y = dy;
    marker.scale.z = dz;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    rds->publisher->publish(marker);
}
