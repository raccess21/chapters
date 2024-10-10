describe("ducksay()", {
  it("can print to console with a `cat`", {
    expect_output(cat(ducksay()))
  })
  it("can can say hello to the world", {
    expect_match(ducksay(), "hello, world")
  })
  it("can can say hello with a duck", {
    duck <- paste(
      "hello, world",
      ">(. )___",
      " (_____/",
      sep = "\n"
    )
    expect_match(ducksay(), duck, fixed = TRUE)
  })
  it("can can say any given phrase", {
    expect_match(ducksay("quack!"), "quack!")
  })
  
})