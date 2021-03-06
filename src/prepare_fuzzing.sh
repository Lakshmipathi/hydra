#!/bin/sh

WD=${PWD}

echo core >/proc/sys/kernel/core_pattern

cd /sys/devices/system/cpu
echo performance | tee cpu*/cpufreq/scaling_governor

echo 1 > /proc/sys/kernel/sched_child_runs_first
echo 1 > /proc/sys/kernel/sched_autogroup_enabled

$WD/utils/mkmounts -u tmpfs-separate
$WD/utils/mkmounts tmpfs-separate

