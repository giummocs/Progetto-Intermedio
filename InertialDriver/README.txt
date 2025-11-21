
std::ostream& InertialDriver::print() const{
	std::ostream& out = std::cout;
	
	if (first == last) {
        out << "Nessuna misura da stampare.\n";
        return out;
    }
	
	int index_last = (last - 1 + BUFFER_DIM) % BUFFER_DIM;
    
    out << "\nUltima Misura Salvata\n";
	for(int i = 0; i < 17; i++)
	{
	    out << "Sensore " << i + 1 << ":\n";
		out << "Yaw_v = " << v[index_last][i].yaw_v << "\n";
		out << "Yaw_a = " << v[index_last][i].yaw_a << "\n";
	    out << "Pitch_v = " << v[index_last][i].pitch_v << "\n";
	    out << "Pitch_a = " << v[index_last][i].pitch_a << "\n";
	    out << "Roll_v = " << v[index_last][i].roll_v << "\n";
	    out << "Roll_a = " << v[index_last][i].roll_a << "\n\n";
	}
    return out;
}
