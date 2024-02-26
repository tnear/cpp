# LLVM IR

Under Add Pane, choose `LLVM IR`.

C++:
```cpp
int popcount(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // clear LSB
        count++;
    }
    return count;
}
```

LLVM IR:
```
module asm ".globl _ZSt21ios_base_library_initv"

define dso_local noundef i32 @popcount(int)(i32 noundef %n) local_unnamed_addr {
entry:
  tail call void @llvm.dbg.value(metadata i32 %n, metadata !1137, metadata !DIExpression())
  tail call void @llvm.dbg.value(metadata i32 0, metadata !1138, metadata !DIExpression())
  %tobool.not4 = icmp eq i32 %n, 0
  br i1 %tobool.not4, label %while.end, label %while.body

while.body:
  %count.06 = phi i32 [ %inc, %while.body ], [ 0, %entry ]
  %n.addr.05 = phi i32 [ %and, %while.body ], [ %n, %entry ]
  tail call void @llvm.dbg.value(metadata i32 %count.06, metadata !1138, metadata !DIExpression())
  tail call void @llvm.dbg.value(metadata i32 %n.addr.05, metadata !1137, metadata !DIExpression())
  %sub = add nsw i32 %n.addr.05, -1
  %and = and i32 %sub, %n.addr.05
  tail call void @llvm.dbg.value(metadata i32 %and, metadata !1137, metadata !DIExpression())
  %inc = add nuw nsw i32 %count.06, 1
  tail call void @llvm.dbg.value(metadata i32 %inc, metadata !1138, metadata !DIExpression())
  %tobool.not = icmp eq i32 %and, 0
  br i1 %tobool.not, label %while.end, label %while.body

while.end:
  %count.0.lcssa = phi i32 [ 0, %entry ], [ %inc, %while.body ]
  ret i32 %count.0.lcssa
}

declare void @llvm.dbg.value(metadata, metadata, metadata) #1
```
