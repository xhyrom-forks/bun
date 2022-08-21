const std = @import("std");
//const uinstd = @cImport(@cInclude("unistd.h"));

//pub fn get_total_memory() u64 {
//    const pages = uinstd.sysconf(uinstd._SC_PHYS_PAGES);
//    const page_size = uinstd.sysconf(uinstd._SC_PAGE_SIZE);
//
//    return @bitCast(u64, pages) * @bitCast(u64, page_size);
//}
const sysResource = @cImport(@cInclude("sys/resource.h"));

pub fn main() void {
    std.debug.print("priority: {}", .{sysResource.getpriority(sysResource.PRIO_PROCESS, 0)});
    //std.debug.print("FREE: {}", .{pages2 * page_size});
}
