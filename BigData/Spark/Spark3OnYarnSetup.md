# Setup Spark on Yarn 3.0 on aws ec2

## Network
```
# edit /etc/hosts in all nodes
[ip]    master
[ip]    slave

# Authorize SSH connections between nodes
Master:  
ssh-keygen -t rsa -b 2048  
All nodes:  
echo ~/.ssh/id_rsa.pub(Master) >> ~/.ssh/authorized_keys  
```
## Prerequisites
```
sudo yum install -y java-1.8.0-openjdk.x86_64
sudo ln -s java-1.8.0-openjdk-1.8.0.222.b10-0.amzn2.0.1.x86_64/jre jre-1.8.0-openjdk.x86_64
sudo update-alternatives --config java
echo 'JAVA_HOME=$(readlink -e /usr/bin/java | sed "s/\(.*\)bin\/java$/\1/")' >> /home/ec2-user/.bashrc
​
echo 'export JAVA_HOME' >> /home/ec2-user/.bashrc
​
# LOCAL IP can only be set in controller
echo 'LOCAL_IP=$(/usr/bin/curl -s http://169.254.169.254/latest/meta-data/local-ipv4)' >> /home/ec2-user/.bashrc
echo 'export LOCAL_IP' >> /home/ec2-user/.bashrc
​
echo 'OWNER=ec2-user' >> /home/ec2-user/.bashrc
echo 'export OWNER' >> /home/ec2-user/.bashrc
source /home/ec2-user/.bashrc
```

## Set up Hadoop

## Set up Spark
```
cd /opt/  
sudo wget http://apache.communilink.net/spark/spark-3.0.0-preview2/spark-3.0.0-preview2-bin-hadoop2.7.tgz  

```


## Source
[spark on yarn 安装部署](https://www.cnblogs.com/cornerxin/p/10689239.html)  
[spark on yarn 安装配置](http://blog.51yip.com/hadoop/2022.html)  
[AWS EC2 搭建 Hadoop 和 Spark 集群](https://www.cnblogs.com/massquantity/p/12088449.html)  
[Install Apache Spark on EC2 instances](https://maelfabien.github.io/bigdata/Spark/#)  
[Spark on Yarn资源配置](https://www.jianshu.com/p/31d89cc4d279)  
[a script to help you quickly setup a dynamic YARN cluster on EC2](https://github.com/tqchen/yarn-ec2)  
[Spark on Yarn Config](https://www.jianshu.com/p/34a6c55042e4)
[一文读懂spark yarn集群搭建](https://www.cnblogs.com/yuanyifei1/p/8474196.html)