while 1>0
do	
	echo 1 > "/sys/class/gpio/gpio0/value"
	sleep 0.5s
	echo 0 > "/sys/class/gpio/gpio0/value"
	sleep 0.5s
done

