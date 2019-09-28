perf record -a -g -o perf.data &

PID=` ps aux | grep "perf record" | grep -v grep | awk '{print $2}' `

if [ -n "$PID" ]; then
sleep $ 1
kill -s INT $PID
fi

# wait until perf exite
sleep 1

perf script -i perf.data & > perf.unfold
perl stackcollapse-perf.pl perf.unfold & > perf.folded
perl flamegraph.pl perf.folded >perf.svg 
