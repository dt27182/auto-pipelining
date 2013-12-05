#set_fp_macro_array -name dcache -elements [list [get_cells "Tile/dcache/data/T12/sram Tile/dcache/data/T40/sram Tile/dcache/data/T85/sram Tile/dcache/data/T112/sram Tile/dcache/meta/tags/sram"]] -x_offset 10 -y_offset 10 -align_edge top -rectilinear
set_fp_macro_array -name dcache -elements [list [get_cells "Tile/dcache/data/T12/sram Tile/dcache/data/T40/sram Tile/dcache/data/T85/sram Tile/dcache/data/T112/sram"]] -x_offset 10 -y_offset 10 -align_edge top -rectilinear
#set_fp_macro_array -name icache -elements [list [get_cells "Tile/icache/icache/T190/sram Tile/icache/icache/T214/sram Tile/icache/icache/tag_array/sram"]] -x_offset 10 -y_offset 10 -align_edge bottom -rectilinear
set_fp_macro_array -name icache -elements [list [get_cells "Tile/icache/icache/T190/sram Tile/icache/icache/T214/sram"]] -x_offset 10 -y_offset 10 -align_edge bottom -rectilinear
set_fp_macro_options dcache -anchor_bound t 
set_fp_macro_options icache -anchor_bound b
