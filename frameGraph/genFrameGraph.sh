sudo perf record -g -p $1 # <pid> 
sudo perf script > perf.unfold
perl ~/FlameGraph/stackcollapse-perf.pl perf.unfold > perf.folded
perl ~/FlameGraph/flamegraph.pl perf.folded > perf.svg
