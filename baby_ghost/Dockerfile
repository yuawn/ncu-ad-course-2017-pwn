FROM ubuntu
MAINTAINER yuawn
RUN apt-get update
RUN apt-get install xinetd -y
RUN apt-get install libc6-dev-i386 -y
RUN useradd -m baby_ghost
RUN chown -R root:root /home/baby_ghost
CMD ["/usr/sbin/xinetd","-dontfork"]