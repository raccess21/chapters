downloader <- function(path, name) {
  download.file(path, name)
  unzip(name)
  file.remove(name)
}

get_source <- function(number, rtype) {
  spath <- paste0("https://cdn.cs50.net/r/2024/x/lectures/", number, "/")
  sfile <- paste0("src", number, ".zip")
  downloader(paste0(spath, sfile), sfile)
}

get_source(5)