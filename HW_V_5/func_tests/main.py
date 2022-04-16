from sys import argv

script_name, file_name = argv
with open(file_name, "rt") as subject:
    with open("extract_{}".format(file_name), "wt") as result:
        for line in subject:
            data = line.split(" ")
            actual_data = []
            for word in data:
                if len([s for s in word if s.isdigit()]) > 0:
                    actual_data.append(word + " ")
                    continue
            actual_line = "".join(actual_data).rstrip(" ")
            result.write(actual_line)