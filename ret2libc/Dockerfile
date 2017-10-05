FROM ubuntu
MAINTAINER yuawn
RUN apt-get update
RUN apt-get install xinetd -y
RUN apt-get install libc6-dev-i386 -y
RUN useradd -m ret2libc
RUN chown -R root:root /home/ret2libc
CMD ["/usr/sbin/xinetd","-dontfork"]