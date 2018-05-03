KERNEL_PATH=arch/arm/boot/zImage
KERNEL_PATH=arch/x86/boot/bzImage
QEMU_PATH=/usr/local/bin/qemu-system-arm
QEMU_PATH=/usr/bin/qemu-system-x86_64
#QEMU_PATH=/home/hon/qemu/x86_64-softmmu/qemu-system-x86_64

$QEMU_PATH \
-nographic	\
-smp 4 \
-M pc \
-m 2048 \
-kernel $KERNEL_PATH \
--append "root=/dev/sda console=ttyS0 ip=192.168.0.110:255.255.255.0" \
-drive file=./rootfs.ext4,format=raw \
-fsdev local,id=my9p,path=./fsdir,security_model=none -device virtio-9p-pci,fsdev=my9p,mount_tag=r \
-net nic,vlan=0 -net tap,vlan=0,ifname=tap0,script=no,downscript=no \
--enable-kvm \
-S -gdb tcp::7852

#-blockdev driver=raw,node-name=disk,file.driver=file,file.filename=disk_1G.img \
#-drive id=data,file=disk_1G.img,cache=none,fi=none,werror=stop -device scsi-disk,drive=data\
#-drive id=data,file=disk_1G.img,cache=none,fi=none,werror=stop -device scsi-disk,drive=id_root \
#-drive file=rootfs.ext2,if=none,id=id_root -device virtio-blk-device,drive=id_root 
#-S -gdb tcp::7852
#--append "root=/dev/sda console=ttyS0 ip=192.168.0.110:255.255.255.0" \
#-fsdev local,id=my9p,path=./fsdir,security_model=none -device virtio-9p-device,fsdev=my9p,mount_tag=r \
#-drive id=data,file=disk_2G.img,cache=none,fi=none,rerror=shtop,werror=stop -device scsi-disk,drive=id_root \
#--enable-kvm \
#-fsdev local,id=my9p,path=./fsdir,security_model=none -device virtio-9p-pci,fsdev=my9p,mount_tag=r \
#-net nic,vlan=0 -net tap,vlan=0,ifname=tap0,script=no,downscript=no \
