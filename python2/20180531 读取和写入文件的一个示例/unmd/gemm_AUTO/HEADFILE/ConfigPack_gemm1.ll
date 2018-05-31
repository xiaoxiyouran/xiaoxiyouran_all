; ModuleID = 'Unknown'
target datalayout = "e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

; Function Attrs: nounwind
define void @ConfigPack_gemm1(i32* %A, i32* %B, i32* %C) #0 {
entry:
  %A.addr = alloca i32*, align 4
  %B.addr = alloca i32*, align 4
  %C.addr = alloca i32*, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  store i32* %A, i32** %A.addr, align 4
  store i32* %B, i32** %B.addr, align 4
  store i32* %C, i32** %C.addr, align 4
  %0 = load i32** %A.addr, align 4
  call void @__gr_malloc(i32* %0, i32 0)
  %1 = load i32** %B.addr, align 4
  call void @__gr_malloc(i32* %1, i32 512)
  %2 = load i32** %C.addr, align 4
  call void @__gr_malloc(i32* %2, i32 1024)
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc140, %entry
  %3 = load i32* %i, align 4
  %cmp = icmp slt i32 %3, 8
  br i1 %cmp, label %for.body, label %for.end142

for.body:                                         ; preds = %for.cond
  store i32 0, i32* %j, align 4
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc137, %for.body
  %4 = load i32* %j, align 4
  %cmp2 = icmp slt i32 %4, 16
  br i1 %cmp2, label %for.body3, label %for.end139

for.body3:                                        ; preds = %for.cond1
  store i32 0, i32* %k, align 4
  br label %for.cond4

for.cond4:                                        ; preds = %for.inc, %for.body3
  %5 = load i32* %k, align 4
  %cmp5 = icmp slt i32 %5, 16
  br i1 %cmp5, label %for.body6, label %for.end

for.body6:                                        ; preds = %for.cond4
  %6 = load i32* %i, align 4
  %mul = mul nsw i32 %6, 16
  %7 = load i32* %k, align 4
  %add = add nsw i32 %mul, %7
  %8 = load i32** %A.addr, align 4
  %arrayidx = getelementptr inbounds i32* %8, i32 %add
  %9 = load i32* %arrayidx, align 4
  %10 = load i32* %k, align 4
  %mul7 = mul nsw i32 %10, 16
  %11 = load i32* %j, align 4
  %add8 = add nsw i32 %mul7, %11
  %12 = load i32** %B.addr, align 4
  %arrayidx9 = getelementptr inbounds i32* %12, i32 %add8
  %13 = load i32* %arrayidx9, align 4
  %mul10 = mul nsw i32 %9, %13
  %14 = load i32* %i, align 4
  %mul11 = mul nsw i32 %14, 16
  %15 = load i32* %j, align 4
  %add12 = add nsw i32 %mul11, %15
  %16 = load i32** %C.addr, align 4
  %arrayidx13 = getelementptr inbounds i32* %16, i32 %add12
  %17 = load i32* %arrayidx13, align 4
  %add14 = add nsw i32 %mul10, %17
  %18 = load i32* %i, align 4
  %mul15 = mul nsw i32 %18, 16
  %19 = load i32* %j, align 4
  %add16 = add nsw i32 %mul15, %19
  %20 = load i32** %C.addr, align 4
  %arrayidx17 = getelementptr inbounds i32* %20, i32 %add16
  store i32 %add14, i32* %arrayidx17, align 4
  %21 = load i32* %i, align 4
  %mul18 = mul nsw i32 %21, 16
  %22 = load i32* %k, align 4
  %add19 = add nsw i32 %mul18, %22
  %23 = load i32** %A.addr, align 4
  %arrayidx20 = getelementptr inbounds i32* %23, i32 %add19
  %24 = load i32* %arrayidx20, align 4
  %25 = load i32* %k, align 4
  %mul21 = mul nsw i32 %25, 16
  %26 = load i32* %j, align 4
  %add22 = add nsw i32 %mul21, %26
  %add23 = add nsw i32 %add22, 1
  %27 = load i32** %B.addr, align 4
  %arrayidx24 = getelementptr inbounds i32* %27, i32 %add23
  %28 = load i32* %arrayidx24, align 4
  %mul25 = mul nsw i32 %24, %28
  %29 = load i32* %i, align 4
  %mul26 = mul nsw i32 %29, 16
  %30 = load i32* %j, align 4
  %add27 = add nsw i32 %mul26, %30
  %add28 = add nsw i32 %add27, 1
  %31 = load i32** %C.addr, align 4
  %arrayidx29 = getelementptr inbounds i32* %31, i32 %add28
  %32 = load i32* %arrayidx29, align 4
  %add30 = add nsw i32 %mul25, %32
  %33 = load i32* %i, align 4
  %mul31 = mul nsw i32 %33, 16
  %34 = load i32* %j, align 4
  %add32 = add nsw i32 %mul31, %34
  %add33 = add nsw i32 %add32, 1
  %35 = load i32** %C.addr, align 4
  %arrayidx34 = getelementptr inbounds i32* %35, i32 %add33
  store i32 %add30, i32* %arrayidx34, align 4
  %36 = load i32* %i, align 4
  %mul35 = mul nsw i32 %36, 16
  %37 = load i32* %k, align 4
  %add36 = add nsw i32 %mul35, %37
  %38 = load i32** %A.addr, align 4
  %arrayidx37 = getelementptr inbounds i32* %38, i32 %add36
  %39 = load i32* %arrayidx37, align 4
  %40 = load i32* %k, align 4
  %mul38 = mul nsw i32 %40, 16
  %41 = load i32* %j, align 4
  %add39 = add nsw i32 %mul38, %41
  %add40 = add nsw i32 %add39, 2
  %42 = load i32** %B.addr, align 4
  %arrayidx41 = getelementptr inbounds i32* %42, i32 %add40
  %43 = load i32* %arrayidx41, align 4
  %mul42 = mul nsw i32 %39, %43
  %44 = load i32* %i, align 4
  %mul43 = mul nsw i32 %44, 16
  %45 = load i32* %j, align 4
  %add44 = add nsw i32 %mul43, %45
  %add45 = add nsw i32 %add44, 2
  %46 = load i32** %C.addr, align 4
  %arrayidx46 = getelementptr inbounds i32* %46, i32 %add45
  %47 = load i32* %arrayidx46, align 4
  %add47 = add nsw i32 %mul42, %47
  %48 = load i32* %i, align 4
  %mul48 = mul nsw i32 %48, 16
  %49 = load i32* %j, align 4
  %add49 = add nsw i32 %mul48, %49
  %add50 = add nsw i32 %add49, 2
  %50 = load i32** %C.addr, align 4
  %arrayidx51 = getelementptr inbounds i32* %50, i32 %add50
  store i32 %add47, i32* %arrayidx51, align 4
  %51 = load i32* %i, align 4
  %mul52 = mul nsw i32 %51, 16
  %52 = load i32* %k, align 4
  %add53 = add nsw i32 %mul52, %52
  %53 = load i32** %A.addr, align 4
  %arrayidx54 = getelementptr inbounds i32* %53, i32 %add53
  %54 = load i32* %arrayidx54, align 4
  %55 = load i32* %k, align 4
  %mul55 = mul nsw i32 %55, 16
  %56 = load i32* %j, align 4
  %add56 = add nsw i32 %mul55, %56
  %add57 = add nsw i32 %add56, 3
  %57 = load i32** %B.addr, align 4
  %arrayidx58 = getelementptr inbounds i32* %57, i32 %add57
  %58 = load i32* %arrayidx58, align 4
  %mul59 = mul nsw i32 %54, %58
  %59 = load i32* %i, align 4
  %mul60 = mul nsw i32 %59, 16
  %60 = load i32* %j, align 4
  %add61 = add nsw i32 %mul60, %60
  %add62 = add nsw i32 %add61, 3
  %61 = load i32** %C.addr, align 4
  %arrayidx63 = getelementptr inbounds i32* %61, i32 %add62
  %62 = load i32* %arrayidx63, align 4
  %add64 = add nsw i32 %mul59, %62
  %63 = load i32* %i, align 4
  %mul65 = mul nsw i32 %63, 16
  %64 = load i32* %j, align 4
  %add66 = add nsw i32 %mul65, %64
  %add67 = add nsw i32 %add66, 3
  %65 = load i32** %C.addr, align 4
  %arrayidx68 = getelementptr inbounds i32* %65, i32 %add67
  store i32 %add64, i32* %arrayidx68, align 4
  %66 = load i32* %i, align 4
  %mul69 = mul nsw i32 %66, 16
  %67 = load i32* %k, align 4
  %add70 = add nsw i32 %mul69, %67
  %68 = load i32** %A.addr, align 4
  %arrayidx71 = getelementptr inbounds i32* %68, i32 %add70
  %69 = load i32* %arrayidx71, align 4
  %70 = load i32* %k, align 4
  %mul72 = mul nsw i32 %70, 16
  %71 = load i32* %j, align 4
  %add73 = add nsw i32 %mul72, %71
  %add74 = add nsw i32 %add73, 4
  %72 = load i32** %B.addr, align 4
  %arrayidx75 = getelementptr inbounds i32* %72, i32 %add74
  %73 = load i32* %arrayidx75, align 4
  %mul76 = mul nsw i32 %69, %73
  %74 = load i32* %i, align 4
  %mul77 = mul nsw i32 %74, 16
  %75 = load i32* %j, align 4
  %add78 = add nsw i32 %mul77, %75
  %add79 = add nsw i32 %add78, 4
  %76 = load i32** %C.addr, align 4
  %arrayidx80 = getelementptr inbounds i32* %76, i32 %add79
  %77 = load i32* %arrayidx80, align 4
  %add81 = add nsw i32 %mul76, %77
  %78 = load i32* %i, align 4
  %mul82 = mul nsw i32 %78, 16
  %79 = load i32* %j, align 4
  %add83 = add nsw i32 %mul82, %79
  %add84 = add nsw i32 %add83, 4
  %80 = load i32** %C.addr, align 4
  %arrayidx85 = getelementptr inbounds i32* %80, i32 %add84
  store i32 %add81, i32* %arrayidx85, align 4
  %81 = load i32* %i, align 4
  %mul86 = mul nsw i32 %81, 16
  %82 = load i32* %k, align 4
  %add87 = add nsw i32 %mul86, %82
  %83 = load i32** %A.addr, align 4
  %arrayidx88 = getelementptr inbounds i32* %83, i32 %add87
  %84 = load i32* %arrayidx88, align 4
  %85 = load i32* %k, align 4
  %mul89 = mul nsw i32 %85, 16
  %86 = load i32* %j, align 4
  %add90 = add nsw i32 %mul89, %86
  %add91 = add nsw i32 %add90, 5
  %87 = load i32** %B.addr, align 4
  %arrayidx92 = getelementptr inbounds i32* %87, i32 %add91
  %88 = load i32* %arrayidx92, align 4
  %mul93 = mul nsw i32 %84, %88
  %89 = load i32* %i, align 4
  %mul94 = mul nsw i32 %89, 16
  %90 = load i32* %j, align 4
  %add95 = add nsw i32 %mul94, %90
  %add96 = add nsw i32 %add95, 5
  %91 = load i32** %C.addr, align 4
  %arrayidx97 = getelementptr inbounds i32* %91, i32 %add96
  %92 = load i32* %arrayidx97, align 4
  %add98 = add nsw i32 %mul93, %92
  %93 = load i32* %i, align 4
  %mul99 = mul nsw i32 %93, 16
  %94 = load i32* %j, align 4
  %add100 = add nsw i32 %mul99, %94
  %add101 = add nsw i32 %add100, 5
  %95 = load i32** %C.addr, align 4
  %arrayidx102 = getelementptr inbounds i32* %95, i32 %add101
  store i32 %add98, i32* %arrayidx102, align 4
  %96 = load i32* %i, align 4
  %mul103 = mul nsw i32 %96, 16
  %97 = load i32* %k, align 4
  %add104 = add nsw i32 %mul103, %97
  %98 = load i32** %A.addr, align 4
  %arrayidx105 = getelementptr inbounds i32* %98, i32 %add104
  %99 = load i32* %arrayidx105, align 4
  %100 = load i32* %k, align 4
  %mul106 = mul nsw i32 %100, 16
  %101 = load i32* %j, align 4
  %add107 = add nsw i32 %mul106, %101
  %add108 = add nsw i32 %add107, 6
  %102 = load i32** %B.addr, align 4
  %arrayidx109 = getelementptr inbounds i32* %102, i32 %add108
  %103 = load i32* %arrayidx109, align 4
  %mul110 = mul nsw i32 %99, %103
  %104 = load i32* %i, align 4
  %mul111 = mul nsw i32 %104, 16
  %105 = load i32* %j, align 4
  %add112 = add nsw i32 %mul111, %105
  %add113 = add nsw i32 %add112, 6
  %106 = load i32** %C.addr, align 4
  %arrayidx114 = getelementptr inbounds i32* %106, i32 %add113
  %107 = load i32* %arrayidx114, align 4
  %add115 = add nsw i32 %mul110, %107
  %108 = load i32* %i, align 4
  %mul116 = mul nsw i32 %108, 16
  %109 = load i32* %j, align 4
  %add117 = add nsw i32 %mul116, %109
  %add118 = add nsw i32 %add117, 6
  %110 = load i32** %C.addr, align 4
  %arrayidx119 = getelementptr inbounds i32* %110, i32 %add118
  store i32 %add115, i32* %arrayidx119, align 4
  %111 = load i32* %i, align 4
  %mul120 = mul nsw i32 %111, 16
  %112 = load i32* %k, align 4
  %add121 = add nsw i32 %mul120, %112
  %113 = load i32** %A.addr, align 4
  %arrayidx122 = getelementptr inbounds i32* %113, i32 %add121
  %114 = load i32* %arrayidx122, align 4
  %115 = load i32* %k, align 4
  %mul123 = mul nsw i32 %115, 16
  %116 = load i32* %j, align 4
  %add124 = add nsw i32 %mul123, %116
  %add125 = add nsw i32 %add124, 7
  %117 = load i32** %B.addr, align 4
  %arrayidx126 = getelementptr inbounds i32* %117, i32 %add125
  %118 = load i32* %arrayidx126, align 4
  %mul127 = mul nsw i32 %114, %118
  %119 = load i32* %i, align 4
  %mul128 = mul nsw i32 %119, 16
  %120 = load i32* %j, align 4
  %add129 = add nsw i32 %mul128, %120
  %add130 = add nsw i32 %add129, 7
  %121 = load i32** %C.addr, align 4
  %arrayidx131 = getelementptr inbounds i32* %121, i32 %add130
  %122 = load i32* %arrayidx131, align 4
  %add132 = add nsw i32 %mul127, %122
  %123 = load i32* %i, align 4
  %mul133 = mul nsw i32 %123, 16
  %124 = load i32* %j, align 4
  %add134 = add nsw i32 %mul133, %124
  %add135 = add nsw i32 %add134, 7
  %125 = load i32** %C.addr, align 4
  %arrayidx136 = getelementptr inbounds i32* %125, i32 %add135
  store i32 %add132, i32* %arrayidx136, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body6
  %126 = load i32* %k, align 4
  %inc = add nsw i32 %126, 1
  store i32 %inc, i32* %k, align 4
  br label %for.cond4

for.end:                                          ; preds = %for.cond4
  br label %for.inc137

for.inc137:                                       ; preds = %for.end
  %127 = load i32* %j, align 4
  %add138 = add nsw i32 %127, 8
  store i32 %add138, i32* %j, align 4
  br label %for.cond1

for.end139:                                       ; preds = %for.cond1
  br label %for.inc140

for.inc140:                                       ; preds = %for.end139
  %128 = load i32* %i, align 4
  %inc141 = add nsw i32 %128, 1
  store i32 %inc141, i32* %i, align 4
  br label %for.cond

for.end142:                                       ; preds = %for.cond
  ret void
}

declare void @__gr_malloc(i32*, i32)

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
