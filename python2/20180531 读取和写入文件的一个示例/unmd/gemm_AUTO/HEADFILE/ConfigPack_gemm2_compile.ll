; ModuleID = 'ConfigPack_gemm2.ll'
target datalayout = "e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

; Function Attrs: nounwind
define void @ConfigPack_gemm2(i32* %A, i32* %B, i32* %C) #0 {
entry:
  call void @__gr_malloc(i32* %A, i32 0)
  call void @__gr_malloc(i32* %B, i32 512)
  call void @__gr_malloc(i32* %C, i32 1024)
  br label %for.cond

for.cond:                                         ; preds = %for.inc140, %entry
  %i.0 = phi i32 [ 8, %entry ], [ %inc141, %for.inc140 ]
  %cmp = icmp slt i32 %i.0, 16
  br i1 %cmp, label %for.cond1, label %for.end142

for.cond1:                                        ; preds = %for.cond, %for.inc137
  %j.0 = phi i32 [ %add138, %for.inc137 ], [ 0, %for.cond ]
  %cmp2 = icmp slt i32 %j.0, 16
  br i1 %cmp2, label %for.cond4, label %for.inc140

for.cond4:                                        ; preds = %for.cond1, %for.body6
  %k.0 = phi i32 [ %inc, %for.body6 ], [ 0, %for.cond1 ]
  %cmp5 = icmp slt i32 %k.0, 16
  br i1 %cmp5, label %for.body6, label %for.inc137

for.body6:                                        ; preds = %for.cond4
  %mul = mul nsw i32 %i.0, 16
  %add = add nsw i32 %mul, %k.0
  %arrayidx = getelementptr inbounds i32* %A, i32 %add
  %0 = load i32* %arrayidx, align 4
  %mul7 = mul nsw i32 %k.0, 16
  %add8 = add nsw i32 %mul7, %j.0
  %arrayidx9 = getelementptr inbounds i32* %B, i32 %add8
  %1 = load i32* %arrayidx9, align 4
  %mul10 = mul nsw i32 %0, %1
  %mul11 = mul nsw i32 %i.0, 16
  %add12 = add nsw i32 %mul11, %j.0
  %arrayidx13 = getelementptr inbounds i32* %C, i32 %add12
  %2 = load i32* %arrayidx13, align 4
  %add14 = add nsw i32 %mul10, %2
  %mul15 = mul nsw i32 %i.0, 16
  %add16 = add nsw i32 %mul15, %j.0
  %arrayidx17 = getelementptr inbounds i32* %C, i32 %add16
  store i32 %add14, i32* %arrayidx17, align 4
  %mul18 = mul nsw i32 %i.0, 16
  %add19 = add nsw i32 %mul18, %k.0
  %arrayidx20 = getelementptr inbounds i32* %A, i32 %add19
  %3 = load i32* %arrayidx20, align 4
  %mul21 = mul nsw i32 %k.0, 16
  %add22 = add nsw i32 %mul21, %j.0
  %add23 = add nsw i32 %add22, 1
  %arrayidx24 = getelementptr inbounds i32* %B, i32 %add23
  %4 = load i32* %arrayidx24, align 4
  %mul25 = mul nsw i32 %3, %4
  %mul26 = mul nsw i32 %i.0, 16
  %add27 = add nsw i32 %mul26, %j.0
  %add28 = add nsw i32 %add27, 1
  %arrayidx29 = getelementptr inbounds i32* %C, i32 %add28
  %5 = load i32* %arrayidx29, align 4
  %add30 = add nsw i32 %mul25, %5
  %mul31 = mul nsw i32 %i.0, 16
  %add32 = add nsw i32 %mul31, %j.0
  %add33 = add nsw i32 %add32, 1
  %arrayidx34 = getelementptr inbounds i32* %C, i32 %add33
  store i32 %add30, i32* %arrayidx34, align 4
  %mul35 = mul nsw i32 %i.0, 16
  %add36 = add nsw i32 %mul35, %k.0
  %arrayidx37 = getelementptr inbounds i32* %A, i32 %add36
  %6 = load i32* %arrayidx37, align 4
  %mul38 = mul nsw i32 %k.0, 16
  %add39 = add nsw i32 %mul38, %j.0
  %add40 = add nsw i32 %add39, 2
  %arrayidx41 = getelementptr inbounds i32* %B, i32 %add40
  %7 = load i32* %arrayidx41, align 4
  %mul42 = mul nsw i32 %6, %7
  %mul43 = mul nsw i32 %i.0, 16
  %add44 = add nsw i32 %mul43, %j.0
  %add45 = add nsw i32 %add44, 2
  %arrayidx46 = getelementptr inbounds i32* %C, i32 %add45
  %8 = load i32* %arrayidx46, align 4
  %add47 = add nsw i32 %mul42, %8
  %mul48 = mul nsw i32 %i.0, 16
  %add49 = add nsw i32 %mul48, %j.0
  %add50 = add nsw i32 %add49, 2
  %arrayidx51 = getelementptr inbounds i32* %C, i32 %add50
  store i32 %add47, i32* %arrayidx51, align 4
  %mul52 = mul nsw i32 %i.0, 16
  %add53 = add nsw i32 %mul52, %k.0
  %arrayidx54 = getelementptr inbounds i32* %A, i32 %add53
  %9 = load i32* %arrayidx54, align 4
  %mul55 = mul nsw i32 %k.0, 16
  %add56 = add nsw i32 %mul55, %j.0
  %add57 = add nsw i32 %add56, 3
  %arrayidx58 = getelementptr inbounds i32* %B, i32 %add57
  %10 = load i32* %arrayidx58, align 4
  %mul59 = mul nsw i32 %9, %10
  %mul60 = mul nsw i32 %i.0, 16
  %add61 = add nsw i32 %mul60, %j.0
  %add62 = add nsw i32 %add61, 3
  %arrayidx63 = getelementptr inbounds i32* %C, i32 %add62
  %11 = load i32* %arrayidx63, align 4
  %add64 = add nsw i32 %mul59, %11
  %mul65 = mul nsw i32 %i.0, 16
  %add66 = add nsw i32 %mul65, %j.0
  %add67 = add nsw i32 %add66, 3
  %arrayidx68 = getelementptr inbounds i32* %C, i32 %add67
  store i32 %add64, i32* %arrayidx68, align 4
  %mul69 = mul nsw i32 %i.0, 16
  %add70 = add nsw i32 %mul69, %k.0
  %arrayidx71 = getelementptr inbounds i32* %A, i32 %add70
  %12 = load i32* %arrayidx71, align 4
  %mul72 = mul nsw i32 %k.0, 16
  %add73 = add nsw i32 %mul72, %j.0
  %add74 = add nsw i32 %add73, 4
  %arrayidx75 = getelementptr inbounds i32* %B, i32 %add74
  %13 = load i32* %arrayidx75, align 4
  %mul76 = mul nsw i32 %12, %13
  %mul77 = mul nsw i32 %i.0, 16
  %add78 = add nsw i32 %mul77, %j.0
  %add79 = add nsw i32 %add78, 4
  %arrayidx80 = getelementptr inbounds i32* %C, i32 %add79
  %14 = load i32* %arrayidx80, align 4
  %add81 = add nsw i32 %mul76, %14
  %mul82 = mul nsw i32 %i.0, 16
  %add83 = add nsw i32 %mul82, %j.0
  %add84 = add nsw i32 %add83, 4
  %arrayidx85 = getelementptr inbounds i32* %C, i32 %add84
  store i32 %add81, i32* %arrayidx85, align 4
  %mul86 = mul nsw i32 %i.0, 16
  %add87 = add nsw i32 %mul86, %k.0
  %arrayidx88 = getelementptr inbounds i32* %A, i32 %add87
  %15 = load i32* %arrayidx88, align 4
  %mul89 = mul nsw i32 %k.0, 16
  %add90 = add nsw i32 %mul89, %j.0
  %add91 = add nsw i32 %add90, 5
  %arrayidx92 = getelementptr inbounds i32* %B, i32 %add91
  %16 = load i32* %arrayidx92, align 4
  %mul93 = mul nsw i32 %15, %16
  %mul94 = mul nsw i32 %i.0, 16
  %add95 = add nsw i32 %mul94, %j.0
  %add96 = add nsw i32 %add95, 5
  %arrayidx97 = getelementptr inbounds i32* %C, i32 %add96
  %17 = load i32* %arrayidx97, align 4
  %add98 = add nsw i32 %mul93, %17
  %mul99 = mul nsw i32 %i.0, 16
  %add100 = add nsw i32 %mul99, %j.0
  %add101 = add nsw i32 %add100, 5
  %arrayidx102 = getelementptr inbounds i32* %C, i32 %add101
  store i32 %add98, i32* %arrayidx102, align 4
  %mul103 = mul nsw i32 %i.0, 16
  %add104 = add nsw i32 %mul103, %k.0
  %arrayidx105 = getelementptr inbounds i32* %A, i32 %add104
  %18 = load i32* %arrayidx105, align 4
  %mul106 = mul nsw i32 %k.0, 16
  %add107 = add nsw i32 %mul106, %j.0
  %add108 = add nsw i32 %add107, 6
  %arrayidx109 = getelementptr inbounds i32* %B, i32 %add108
  %19 = load i32* %arrayidx109, align 4
  %mul110 = mul nsw i32 %18, %19
  %mul111 = mul nsw i32 %i.0, 16
  %add112 = add nsw i32 %mul111, %j.0
  %add113 = add nsw i32 %add112, 6
  %arrayidx114 = getelementptr inbounds i32* %C, i32 %add113
  %20 = load i32* %arrayidx114, align 4
  %add115 = add nsw i32 %mul110, %20
  %mul116 = mul nsw i32 %i.0, 16
  %add117 = add nsw i32 %mul116, %j.0
  %add118 = add nsw i32 %add117, 6
  %arrayidx119 = getelementptr inbounds i32* %C, i32 %add118
  store i32 %add115, i32* %arrayidx119, align 4
  %mul120 = mul nsw i32 %i.0, 16
  %add121 = add nsw i32 %mul120, %k.0
  %arrayidx122 = getelementptr inbounds i32* %A, i32 %add121
  %21 = load i32* %arrayidx122, align 4
  %mul123 = mul nsw i32 %k.0, 16
  %add124 = add nsw i32 %mul123, %j.0
  %add125 = add nsw i32 %add124, 7
  %arrayidx126 = getelementptr inbounds i32* %B, i32 %add125
  %22 = load i32* %arrayidx126, align 4
  %mul127 = mul nsw i32 %21, %22
  %mul128 = mul nsw i32 %i.0, 16
  %add129 = add nsw i32 %mul128, %j.0
  %add130 = add nsw i32 %add129, 7
  %arrayidx131 = getelementptr inbounds i32* %C, i32 %add130
  %23 = load i32* %arrayidx131, align 4
  %add132 = add nsw i32 %mul127, %23
  %mul133 = mul nsw i32 %i.0, 16
  %add134 = add nsw i32 %mul133, %j.0
  %add135 = add nsw i32 %add134, 7
  %arrayidx136 = getelementptr inbounds i32* %C, i32 %add135
  store i32 %add132, i32* %arrayidx136, align 4
  %inc = add nsw i32 %k.0, 1
  br label %for.cond4

for.inc137:                                       ; preds = %for.cond4
  %add138 = add nsw i32 %j.0, 8
  br label %for.cond1

for.inc140:                                       ; preds = %for.cond1
  %inc141 = add nsw i32 %i.0, 1
  br label %for.cond

for.end142:                                       ; preds = %for.cond
  ret void
}

declare void @__gr_malloc(i32*, i32)

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
