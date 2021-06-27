# IMAGE OVERHEADED ITS JUST FOR DEMO !!!
FROM ubuntu:20.04

RUN apt-get update && apt-get install -y locales && rm -rf /var/lib/apt/lists/* \
    && localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8
ENV LANG en_US.utf8
ENV TZ=Europe/Minsk
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN cd /var/cache/debconf && \
    rm *.dat && \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y build-essential cmake libgtest-dev libboost-thread-dev libboost-program-options-dev

COPY . /opt/visutech_test
WORKDIR /opt/visutech_test
RUN mkdir build && cd build && \
    cmake .. && make

ENTRYPOINT ["build/visutech_task", "$src", "$word", "$dest"]
