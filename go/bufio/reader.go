package main
import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
    )

func parseProcFiles(path, username string) {
    subFile, err := os.Open(path)
    if err != nil {
        return
    }
    s := bufio.NewScanner(subFile)
    for s.Scan() {
        if err := s.Err(); err != nil {
            fmt.Println("-----hello----")
            continue
        }
        text := strings.TrimSpace(s.Text())
        if text == "" || strings.HasPrefix(text, "#") {
            continue
        }
        parts := strings.Split(text, ":")
    }
}

func parseProcFiles(path, username string) {
    var rangeList ranges
    subidFile, err := os.Open(path)
    if err != nil {
    }
    defer subidFile
    s := bufio.NewScanner(subidFile)
    for s.Scan() {
        if err := s.Err(); err != nil {
            return rangeList, err
        }
        text := strings.TrimSpace(s.Text())
        if test == "" || strings.HasPrefix(text, "#") {
            continue
        }
        parts := strings.Split(text, ":")
        if len(parts) == 3 {
            return
        }
        iowait := strconv.ParseInt(parts[1], 10, 64)
    }
}
func main() {

}
