func checkRecord(s string) bool {
	abs := 0
	late := false
	sumlate := 0
	for _, v := range s {
		if v == 'A' {
			abs++
		} else if v == 'L' {
			sumlate++
		}
		if sumlate >= 3 {
			late = true
		}
		sumlate = 0
	}
	return (abs < 2 && late == false)
}